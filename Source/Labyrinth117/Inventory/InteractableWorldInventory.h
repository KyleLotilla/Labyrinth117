// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../World/InteractableWorldObject.h"
#include "../Inventory/Inventory.h"
#include "../UI/DroppedInventoryMenuUI.h"
#include "../Player/PlayerWorldPawn.h"
#include "../Player/PlayerWorldController.h"
#include "InteractableWorldInventory.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOpenWorldInventory);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class LABYRINTH117_API UInteractableWorldInventory : public UInteractableWorldObject
{
	GENERATED_BODY()

public:
	void OnInteractedWithPlayer();
	UFUNCTION(BlueprintCallable) void SetSourceInventory(AInventory* sourceInventory_);

	UPROPERTY(BlueprintAssignable, BlueprintCallable) FOpenWorldInventory onOpenWorldInventoryDelegate;

protected:
	UPROPERTY(EditAnywhere) AInventory* sourceInventory;

};
