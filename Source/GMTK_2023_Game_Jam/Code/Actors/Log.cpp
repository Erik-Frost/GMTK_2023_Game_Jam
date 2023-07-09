// Fill out your copyright notice in the Description page of Project Settings.


#include "Log.h"


// Sets default values
ALog::ALog()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALog::BeginPlay()
{
	Super::BeginPlay();
	movementEnabled = true;
	startingLocation = GetActorLocation();
}

// Called every frame
void ALog::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (movementEnabled)
	{
		FVector NewLocation = GetActorLocation();
		NewLocation.Y += speed * direction;
		SetActorLocation(NewLocation);
		if (direction > 0 && NewLocation.Y > posBound)
		{
			SetActorLocation(startingLocation);
		}
		else if (direction < 0 && NewLocation.Y < negBound)
		{
			SetActorLocation(startingLocation);
		}
	}
	
}


void ALog::EnableAutoMovement(bool enable)
{
	movementEnabled = enable;
}
