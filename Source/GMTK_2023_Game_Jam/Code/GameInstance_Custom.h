// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameInstance_Custom.generated.h"

/**
 * 
 */
UCLASS()
class GMTK_2023_GAME_JAM_API UGameInstance_Custom : public UGameInstance
{
	GENERATED_BODY()
public:

	virtual void Init() override;
	virtual void Shutdown() override;
};
