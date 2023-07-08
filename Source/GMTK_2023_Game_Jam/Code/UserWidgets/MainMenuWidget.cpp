// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

#include "Components/Button.h"

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	PlayButton->OnPressed.AddUniqueDynamic(this, &UMainMenuWidget::OnPlayButtonPressed);
}

void UMainMenuWidget::OnPlayButtonPressed()
{
}
