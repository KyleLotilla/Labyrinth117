// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ItemCategory : uint8
{
	WEAPON = 0 UMETA(DisplayName = "Weapon"),
	ARMOR = 1 UMETA(DisplayName = "Armor"),
	CONSUMABLE = 2 UMETA(DisplayName = "Consumable")
};
