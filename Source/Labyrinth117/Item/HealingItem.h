// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UsableItem.h"
#include "../Player/PlayerWorldPawn.h"
#include "HealingItem.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class LABYRINTH117_API UHealingItem : public UUsableItem
{
	GENERATED_BODY()

public:
	void UseItem();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int healingAmount;
};
