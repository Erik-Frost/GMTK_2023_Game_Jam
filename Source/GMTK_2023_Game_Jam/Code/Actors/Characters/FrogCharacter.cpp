// Copyright Epic Games, Inc. All Rights Reserved.

#include "FrogCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

AFrogCharacter::AFrogCharacter()
{
	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	AutoPossessPlayer = EAutoReceiveInput::Disabled;
	AutoPossessAI = EAutoPossessAI::Disabled;

	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	
	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	MoveIndicatorStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MoveIndicatorStaticMeshComponent"));
	MoveIndicatorStaticMeshComponent->SetupAttachment(RootComponent);
	MoveIndicatorStaticMeshComponent->SetAbsolute(true, true, true);
	
}

void AFrogCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AFrogCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);


	if (CurrentMoveCooldown > 0) CurrentMoveCooldown -= DeltaSeconds;
	else
	{
		
		
		// Move the frog
		if (NextMovePosition != FIntVector2(0, 0))
		{
			auto MoveLocation = RelativeGridLocationToWorld(NextMovePosition);
			SetActorLocation(MoveLocation);
		}



		
		// Find Nearby tiles in bounds
		NearbyTilesInBounds.Empty();
		for (int32 x=-3; x<=3; x++)
		{
			for (int32 y=-3; y<=3; y++)
			{
				FHitResult HitResult;
				FVector Offset = FVector(x * GridSize, y * GridSize, 0);
				FVector Location = RoundLocationToGrid(GetActorLocation() + Offset);
				FVector HalfSize = FVector((GridSize/2)-5, (GridSize/2)-5, (GridSize/2)-20);
				const FRotator Rotation = FRotator::ZeroRotator;
				UKismetSystemLibrary::BoxTraceSingle(GetWorld(), Location, Location,
						HalfSize, Rotation,
						{ UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2) /* Bounds */ },
						false, {this}, EDrawDebugTrace::ForDuration, HitResult,
						true, FLinearColor::Red, FLinearColor::Green, 1);

				// 
				if (IsValid(HitResult.GetActor())) continue;
				NearbyTilesInBounds.Add(FIntVector2(x, y));
			}
		}

		
		// Pick the next move location
		NextMovePosition = PickNextMoveLocation();


		MoveIndicatorStaticMeshComponent->SetWorldLocation(RelativeGridLocationToWorld(NextMovePosition));

		auto LookAtLocation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(),
			RelativeGridLocationToWorld(NextMovePosition));
		SetActorRotation(FRotator::MakeFromEuler(FVector(0,0, LookAtLocation.Yaw)));
		
		
		CurrentMoveCooldown = MoveCooldown;
	}
}

FIntVector2 AFrogCharacter::PickNextMoveLocation()
{
	FIntVector2 NextMove = FIntVector2(0, 0);
	
	auto RandomNum = FMath::RandRange(0, 3);

	if (RandomNum == 0) NextMove = FIntVector2(1, 0); // Forward
	else if (RandomNum == 1) NextMove = FIntVector2(0, 1); // Right
	else if (RandomNum == 3) NextMove = FIntVector2(1, 0); // Forward
	else if (RandomNum == 2) NextMove = FIntVector2(0, -1); // Left

	if (!NearbyTilesInBounds.Contains(NextMove)) return FIntVector2(0, 0);
	return NextMove;
}

FVector AFrogCharacter::RoundLocationToGrid(const FVector& Location)
{
	// Divide location by grid size, round it to the nearest whole number, then multiply by grid size
	FVector GridLocation = GridSize * FVector(
		FMath::RoundToInt(Location.X / GridSize),
		FMath::RoundToInt(Location.Y / GridSize),
		FMath::RoundToInt(Location.Z / GridSize)
	);
	return GridLocation;
}

FVector AFrogCharacter::RelativeGridLocationToWorld(const FIntVector2& GridLocation)
{
	return RoundLocationToGrid(GetActorLocation() +
				FVector(GridLocation.X * GridSize, GridLocation.Y * GridSize, 0));
}
