// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h" 
#include "../Item/Item.h"
#include "ItemRowUI.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FItemRowSelectionDelegate, AItem*, item, int32, index);

UCLASS(BlueprintType, Blueprintable)
class LABYRINTH117_API UItemRowUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void SetItem(AItem* item_);
	UFUNCTION(BlueprintCallable) void SetIndex(int32 index_);
	UFUNCTION(BlueprintCallable) void ItemRowSelected();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UTextBlock* equipped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UTextBlock* itemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 index;
	UPROPERTY(BlueprintReadWrite) AItem* item;

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable) FItemRowSelectionDelegate onItemRowSelectionDelegate;
};
