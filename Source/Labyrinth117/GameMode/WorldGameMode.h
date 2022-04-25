// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "../Player/PlayerWorldController.h"
#include "WorldGameMode.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API AWorldGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void BindToPlayerCombatStats();
	UFUNCTION(BlueprintCallable) void WinGame();
	UFUNCTION(BlueprintCallable) void LoseGame();
};
