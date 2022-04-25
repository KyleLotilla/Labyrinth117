// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EquipItemButtonUI.h"
#include "UseConsumableButtonUI.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h" 
#include "../Item/Equipment.h"
#include "../Inventory/Inventory.h"
#include "../Item/ItemCategory.h"
#include "ItemActionUI.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FItemAction);


UCLASS()
class LABYRINTH117_API UItemActionUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void ItemSelected(AItem* item, int index);
	UFUNCTION(BlueprintCallable) void SetPlayerEquipment(UEquipment* playerEquipment_);
	UFUNCTION(BlueprintCallable) void SetPlayerInventory(AInventory* playerInventory_);
	UFUNCTION(BlueprintCallable) void ClearUI();
	UFUNCTION(BlueprintCallable) void OnItemAction();

	UPROPERTY(BlueprintAssignable) FItemAction onItemActionDelegate;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UHorizontalBox* box;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<UEquipItemButtonUI> equipItemButtonClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<UUseConsumableButtonUI> useConsumableButtonClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UEquipment* playerEquipment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AInventory* playerInventory;
};
