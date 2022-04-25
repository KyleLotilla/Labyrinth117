// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Item/Item.h"
#include "../Item/ItemCategory.h"
#include "../Item/ArmorType.h"
#include "../Item/Armor.h"
#include "../Item/Weapon.h"
#include "Components/TextBlock.h" 
#include "ItemDetailsUI.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API UItemDetailsUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void ClearDetails();
	UFUNCTION(BlueprintCallable) void SetItem(AItem* item);


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UTextBlock* itemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UTextBlock* equipped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UTextBlock* itemStats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UTextBlock* itemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FString> armorTypeNames = {
		FString("Head"),
		FString("Body"),
		FString("Foot"),
	};
};
