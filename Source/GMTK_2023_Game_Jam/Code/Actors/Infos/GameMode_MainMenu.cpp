// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameMode_MainMenu.h"

#include "GMTK_2023_Game_Jam/Code/Actors/Controllers/PlayerController_Custom.h"
#include "UObject/ConstructorHelpers.h"

AGameMode_MainMenu::AGameMode_MainMenu()
{
	// use our custom PlayerController class
	PlayerControllerClass = APlayerController_Custom::StaticClass();

	
}