// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class GMTK_2023_GAME_JAM_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(meta=(BindWidgetOptional))
	UButton* PlayButton = nullptr;
	UPROPERTY(meta=(BindWidgetOptional))
	UButton* CreditsButton = nullptr;
	UPROPERTY(meta=(BindWidgetOptional))
	UButton* QuitButton = nullptr;

	virtual void NativeOnInitialized() override;


	UFUNCTION()
	void PlayButtonPressed();
	UFUNCTION()
	void ButtonPressed();
	UFUNCTION()
	void QuitButtonPressed();
	
};
