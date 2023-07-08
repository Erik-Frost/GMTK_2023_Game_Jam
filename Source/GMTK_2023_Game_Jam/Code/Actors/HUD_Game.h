// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUD_Game.generated.h"

class UGameMenuWidget;

UCLASS()
class GMTK_2023_GAME_JAM_API AHUD_Game : public AHUD
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> GameMenuClass = nullptr;
	
	AHUD_Game();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void OpenGameMenu();

	void CloseAllMenus();

private:

	UPROPERTY(VisibleAnywhere)
	UGameMenuWidget* GameMenu = nullptr;
	
};
