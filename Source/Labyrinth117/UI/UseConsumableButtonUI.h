// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Inventory/Inventory.h"
#include "../Item/UsableItem.h"
#include "UseConsumableButtonUI.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FItemConsumed);


UCLASS()
class LABYRINTH117_API UUseConsumableButtonUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) void SetPlayerInventory(AInventory* playerInventory_);
	UFUNCTION(BlueprintCallable) void SetSelectedIndex(int32 selectedIndex_);
	UFUNCTION(BlueprintCallable) void UseItem();

	UPROPERTY(BlueprintAssignable) FItemConsumed onItemConsumedDelegate;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AInventory* playerInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 selectedIndex = -1;

};
