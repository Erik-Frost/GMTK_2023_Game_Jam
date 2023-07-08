// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode_Game.h"


// Sets default values
AGameMode_Game::AGameMode_Game()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameMode_Game::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameMode_Game::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
