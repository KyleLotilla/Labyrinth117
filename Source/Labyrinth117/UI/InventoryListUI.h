// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemRowUI.h"
#include "../Inventory/Inventory.h"
#include "Components/GridPanel.h" 
#include "InventoryListUI.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API UInventoryListUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) void ReloadList();
	UFUNCTION(BlueprintCallable) void SetInventory(AInventory* inventory_);
	UFUNCTION() void OnItemRowSelected(AItem* item, int32 index);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<UItemRowUI> itemRowUIClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UGridPanel* gridPanel;
	UPROPERTY(BlueprintReadWrite) AInventory* inventory;

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable) FItemRowSelectionDelegate onItemRowSelectionDelegate;
};
