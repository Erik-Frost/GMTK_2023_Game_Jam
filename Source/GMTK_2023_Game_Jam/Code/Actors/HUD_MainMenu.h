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
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> SettingsMenuClass = nullptr;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> CreditsMenuClass = nullptr;
	
	
	AHUD_MainMenu();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void OpenMainMenu();
	void OpenSettingsMenu();
	void OpenCreditsMenu();

	void CloseAllMenus();


private:

	UPROPERTY(VisibleAnywhere)
	UMainMenuWidget* MainMenu = nullptr;
	UPROPERTY(VisibleAnywhere)
	USettingsMenuWidget* SettingsMenu = nullptr;
	UPROPERTY(VisibleAnywhere)
	UCreditsMenuWidget* CreditsMenu = nullptr;
};
