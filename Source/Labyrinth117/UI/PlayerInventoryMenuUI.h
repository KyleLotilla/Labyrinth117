// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Inventory/Inventory.h"
#include "InventoryMenuUI.h"
#include "ItemActionUI.h"
#include "../Item/Equipment.h"
#include "PlayerInventoryMenuUI.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API UPlayerInventoryMenuUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void SetInventory(AInventory* inventory_);
	UFUNCTION(BlueprintCallable) void SetEquipment(UEquipment* equipment_);
	UFUNCTION(BlueprintCallable) void RefreshMenu();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AInventory* inventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UInventoryMenuUI* inventoryMenu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UItemActionUI* itemActionUI;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UEquipment* equipment;
};
