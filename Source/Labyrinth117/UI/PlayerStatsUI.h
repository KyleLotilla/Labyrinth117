// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "../Combat/CombatStats.h"
#include "../Combat/LevelStats.h"
#include "PlayerStatsUI.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API UPlayerStatsUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void SetPlayerCombatStats(UCombatStats* combatStats);
	UFUNCTION(BlueprintCallable) void SetPlayerLevelStats(ULevelStats* levelStats);
	UFUNCTION(BlueprintCallable) void SetAtk(int atk_);
	UFUNCTION(BlueprintCallable) void SetDef(int def_);

protected:
	UPROPERTY(BlueprintReadWrite) UTextBlock* level;
	UPROPERTY(BlueprintReadWrite) UTextBlock* currentExp;
	UPROPERTY(BlueprintReadWrite) UTextBlock* expToLevelUp;
	UPROPERTY(BlueprintReadWrite) UProgressBar* expBar;
	UPROPERTY(BlueprintReadWrite) UTextBlock* baseHP;
	UPROPERTY(BlueprintReadWrite) UTextBlock* currentHP;
	UPROPERTY(BlueprintReadWrite) UProgressBar* healthBar;
	UPROPERTY(BlueprintReadWrite) UTextBlock* atk;
	UPROPERTY(BlueprintReadWrite) UTextBlock* def;
};
