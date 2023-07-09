// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FrogCharacter.generated.h"

UCLASS(Blueprintable)
class AFrogCharacter : public ACharacter
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UAnimMontage> JumpAnimation = nullptr;

	inline static float GridSize = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MoveIndicatorStaticMeshComponent;
	
	

	
	AFrogCharacter();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;


	// In this method, the Frog chooses what tile it is going to move to
	virtual FIntVector2 PickNextMoveLocation();
	
	
	FVector RoundLocationToGrid(const FVector& Location);
	FVector RelativeGridLocationToWorld(const FIntVector2& GridLocation);
	FVector RelativeGridLocationToWorldFromMoveStart(const FIntVector2& GridLocation);

private:

	UPROPERTY(VisibleAnywhere)
	float CurrentMoveCooldown = 0;
	UPROPERTY(EditAnywhere)
	FVector2f MoveCooldown = FVector2f(0.5, 1.5);
	UPROPERTY(EditAnywhere)
	float MoveSpeedInSeconds = 0.3;
	UPROPERTY(VisibleAnywhere)
	float MoveDelta = 0;
	UPROPERTY(VisibleAnywhere)
	TSet<FIntVector2> NearbyTilesInBounds = {};
	UPROPERTY(VisibleAnywhere)
	FIntVector2 NextMovePosition = FIntVector2(0, 0);
	UPROPERTY(VisibleAnywhere)
	FVector MoveStartPosition = FVector(0,0,0);
	UPROPERTY(VisibleAnywhere)
	bool IsMoving = false;
	
	
};

