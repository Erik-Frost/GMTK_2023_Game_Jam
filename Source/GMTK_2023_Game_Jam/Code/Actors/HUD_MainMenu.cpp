// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_MainMenu.h"

#include "GMTK_2023_Game_Jam/Code/UserWidgets/MainMenuWidget.h"


// Sets default values
AHUD_MainMenu::AHUD_MainMenu()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHUD_MainMenu::BeginPlay()
{
	Super::BeginPlay();

	MainMenu = CreateWidget<UMainMenuWidget>(PlayerOwner, MainMenuClass);
	MainMenu->AddToViewport();
}

// Called every frame
void AHUD_MainMenu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


