// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameMode_Game.generated.h"

UCLASS()
class GMTK_2023_GAME_JAM_API AGameMode_Game : public AGameMode
{
	GENERATED_BODY()
public:
	
	
	AGameMode_Game();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;




	
};
