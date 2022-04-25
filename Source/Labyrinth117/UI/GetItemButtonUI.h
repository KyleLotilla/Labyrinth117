// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Inventory/Inventory.h"
#include "GetItemButtonUI.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API UGetItemButtonUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void SetSourceInventory(AInventory* sourceInventory_);
	UFUNCTION(BlueprintCallable) void SetPlayerInventory(AInventory* playerInventory_);
	UFUNCTION(BlueprintCallable) void SetSelectedIndex(int32 selectedIndex_);
	UFUNCTION(BlueprintCallable) void GetItem();
	UFUNCTION(BlueprintCallable) void ClearIndex();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AInventory* sourceInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AInventory* playerInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 selectedIndex = -1;
};
