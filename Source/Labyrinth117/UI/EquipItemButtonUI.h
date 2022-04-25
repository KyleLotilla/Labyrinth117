// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Item/Item.h"
#include "../Item/Equipment.h"
#include "../Item/ItemCategory.h"
#include "EquipItemButtonUI.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FItemEquipped);

UCLASS()
class LABYRINTH117_API UEquipItemButtonUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void EquipSelectedItem();
	UFUNCTION(BlueprintCallable) void SetItem(AItem* item);
	UFUNCTION(BlueprintCallable) void SetPlayerEquipment(UEquipment* playerEquipment_);
	UFUNCTION(BlueprintCallable) void ClearItem();

	UPROPERTY(BlueprintAssignable) FItemEquipped onItemEquippedDelegate;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UEquipment* playerEquipment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AItem* selectedItem;
};
