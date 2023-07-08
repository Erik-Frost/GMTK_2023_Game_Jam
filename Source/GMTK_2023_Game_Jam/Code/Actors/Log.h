// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Log.generated.h"

UCLASS()
class GMTK_2023_GAME_JAM_API ALog : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALog();

	UPROPERTY(EditAnywhere)
	int32 speed;

	UPROPERTY(EditAnywhere)
	float direction = 1;

	UPROPERTY(EditAnywhere)
		int32 negBound;

	UPROPERTY(EditAnywhere)
		int32 posBound;

	FVector startingLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
