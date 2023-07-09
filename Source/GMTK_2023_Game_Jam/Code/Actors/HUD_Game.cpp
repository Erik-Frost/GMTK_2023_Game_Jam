// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_Game.h"

#include "GMTK_2023_Game_Jam/Code/UserWidgets/GameMenuWidget.h"


// Sets default values
AHUD_Game::AHUD_Game()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHUD_Game::BeginPlay()
{
	Super::BeginPlay();

	GameMenu = CreateWidget<UGameMenuWidget>(PlayerOwner, GameMenuClass);
	GameMenu->AddToViewport();
}

// Called every frame
void AHUD_Game::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}





