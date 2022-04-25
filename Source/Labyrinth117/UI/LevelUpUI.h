// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h" 
#include "../Combat/CombatStats.h"
#include "../Combat/LevelUpData.h"
#include "Components/TextBlock.h" 
#include "LevelUpUI.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API ULevelUpUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) void SetLevelUpData(FLevelUpData levelUpData);

protected:
	UPROPERTY(BlueprintReadWrite) UTextBlock* prevLevel;
	UPROPERTY(BlueprintReadWrite) UTextBlock* prevHP;
	UPROPERTY(BlueprintReadWrite) UTextBlock* prevAtk;
	UPROPERTY(BlueprintReadWrite) UTextBlock* prevDef;
	UPROPERTY(BlueprintReadWrite) UTextBlock* currLevel;
	UPROPERTY(BlueprintReadWrite) UTextBlock* currHP;
	UPROPERTY(BlueprintReadWrite) UTextBlock* currAtk;
	UPROPERTY(BlueprintReadWrite) UTextBlock* currDef;
};
