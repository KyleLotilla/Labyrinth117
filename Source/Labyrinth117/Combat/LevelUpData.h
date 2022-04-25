// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelUpData.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct LABYRINTH117_API FLevelUpData
{
	GENERATED_BODY()

	int prevLevel;
	int prevHP;
	int prevAtk;
	int prevDef;
	int currLevel;
	int currHP;
	int currAtk;
	int currDef;
};
