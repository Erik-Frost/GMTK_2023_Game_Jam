// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

#include "Components/Button.h"
#include "GMTK_2023_Game_Jam/Code/GameInstance_Custom.h"
#include "GMTK_2023_Game_Jam/Code/Actors/HUD_MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	PlayButton->OnPressed.AddUniqueDynamic(this, &UMainMenuWidget::PlayButtonPressed);
	CreditsButton->OnPressed.AddUniqueDynamic(this, &UMainMenuWidget::ButtonPressed);
	QuitButton->OnPressed.AddUniqueDynamic(this, &UMainMenuWidget::QuitButtonPressed);
}

void UMainMenuWidget::PlayButtonPressed()
{
	auto GameInstanceLocal = Cast<UGameInstance_Custom>(GetGameInstance());
	UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), GameInstanceLocal->GameLevel);
}

void UMainMenuWidget::ButtonPressed()
{
	if (auto MainMenuHud = Cast<AHUD_MainMenu>(GetOwningPlayer()->GetHUD()))
	{
		MainMenuHud->OpenCreditsMenu();
	}
}

void UMainMenuWidget::QuitButtonPressed()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), GetOwningPlayer(),
		EQuitPreference::Quit, false);
}
