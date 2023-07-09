// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUD_MainMenu.generated.h"

class UCreditsMenuWidget;
class USettingsMenuWidget;
class UMainMenuWidget;

UCLASS()
class GMTK_2023_GAME_JAM_API AHUD_MainMenu : public AHUD
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> MainMenuClass = nullptr;

	
	
	AHUD_MainMenu();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;



private:

	UPROPERTY(VisibleAnywhere)
	UMainMenuWidget* MainMenu = nullptr;

};
