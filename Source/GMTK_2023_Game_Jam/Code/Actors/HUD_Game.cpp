// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_Game.h"

#include "GMTK_2023_Game_Jam/Code/UserWidgets/CreditsMenuWidget.h"
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

	OpenGameMenu();
}

// Called every frame
void AHUD_Game::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHUD_Game::OpenGameMenu()
{
	CloseAllMenus();
	GameMenu->AddToViewport();
}

void AHUD_Game::CloseAllMenus()
{
	if (GameMenu->IsInViewport()) GameMenu->RemoveFromParent();

	// According to the unreal community, widgets don't seem to reliable garbage collect
	// When they have been removed from their parent and all refs to them have been removed
	// Manually calling garbage collect is said to help.
	TryCollectGarbage(RF_NoFlags);
}

