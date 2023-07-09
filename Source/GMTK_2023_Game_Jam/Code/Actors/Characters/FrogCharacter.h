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

private:

	UPROPERTY(VisibleAnywhere)
	float CurrentMoveCooldown = 0;
	UPROPERTY(EditAnywhere)
	float MoveCooldown = 1;
	UPROPERTY(VisibleAnywhere)
	TSet<FIntVector2> NearbyTilesInBounds = {};
	UPROPERTY(VisibleAnywhere)
	FIntVector2 NextMovePosition = FIntVector2(0, 0);
	
	
};

