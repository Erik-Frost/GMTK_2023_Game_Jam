// Copyright Epic Games, Inc. All Rights Reserved.

#include "GMTK_2023_Game_JamGameMode.h"
#include "GMTK_2023_Game_JamPlayerController.h"
#include "GMTK_2023_Game_JamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGMTK_2023_Game_JamGameMode::AGMTK_2023_Game_JamGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGMTK_2023_Game_JamPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}