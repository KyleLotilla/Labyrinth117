// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Inventory/Inventory.h"
#include "GetItemButtonUI.h"
#include "InventoryMenuUI.h"
#include "DroppedInventoryMenuUI.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API UDroppedInventoryMenuUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void SetSourceInventory(AInventory* inventory);
	UFUNCTION(BlueprintCallable) void SetPlayerInventory(AInventory* inventory);
	UFUNCTION(BlueprintCallable) void RefreshMenu();


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UInventoryMenuUI* inventoryMenu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UGetItemButtonUI* getItemButton;
	UPROPERTY(EditAnywhere) AInventory* sourceInventory;
	UPROPERTY(EditAnywhere) AInventory* playerInventory;
};
