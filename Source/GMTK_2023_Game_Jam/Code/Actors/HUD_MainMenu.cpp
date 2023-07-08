// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_MainMenu.h"

#include "GMTK_2023_Game_Jam/Code/UserWidgets/CreditsMenuWidget.h"
#include "GMTK_2023_Game_Jam/Code/UserWidgets/MainMenuWidget.h"
#include "GMTK_2023_Game_Jam/Code/UserWidgets/SettingsMenuWidget.h"


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
	SettingsMenu = CreateWidget<USettingsMenuWidget>(PlayerOwner, SettingsMenuClass);

	OpenMainMenu();
	
}

// Called every frame
void AHUD_MainMenu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHUD_MainMenu::OpenMainMenu()
{
	CloseAllMenus();
	MainMenu->AddToViewport();
}

void AHUD_MainMenu::OpenSettingsMenu()
{
	CloseAllMenus();
	SettingsMenu->AddToViewport();
}

void AHUD_MainMenu::OpenCreditsMenu()
{
	CloseAllMenus();
	CreditsMenu->AddToViewport();
}

void AHUD_MainMenu::CloseAllMenus()
{
	if (MainMenu->IsInViewport()) MainMenu->RemoveFromParent();
	if (SettingsMenu->IsInViewport()) SettingsMenu->RemoveFromParent();
	if (CreditsMenu->IsInViewport()) CreditsMenu->RemoveFromParent();

	// According to the unreal community, widgets don't seem to reliable garbage collect
	// When they have been removed from their parent and all refs to them have been removed
	// Manually calling garbage collect is said to help.
	TryCollectGarbage(RF_NoFlags);
}

