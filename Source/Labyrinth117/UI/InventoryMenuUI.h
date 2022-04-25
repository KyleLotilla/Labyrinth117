// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Inventory/Inventory.h"
#include "InventoryListUI.h"
#include "ItemDetailsUI.h"
#include "InventoryMenuUI.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API UInventoryMenuUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void RefreshMenu();
	UFUNCTION(BlueprintCallable) void SetInventory(AInventory* inventory_);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UInventoryListUI* inventoryList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UItemDetailsUI* itemDetails;
	UPROPERTY(EditAnywhere) AInventory* inventory;

};
