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

	UPROPERTY(meta=(BindWidget))
	UButton* PlayButton = nullptr;
	UPROPERTY(meta=(BindWidget))
	UButton* CreditsButton = nullptr;
	UPROPERTY(meta=(BindWidget))
	UButton* QuitButton = nullptr;

	virtual void NativeOnInitialized() override;


	UFUNCTION()
	void PlayButtonPressed();
	UFUNCTION()
	void ButtonPressed();
	UFUNCTION()
	void QuitButtonPressed();
	
};
