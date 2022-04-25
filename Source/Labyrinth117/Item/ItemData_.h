// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "Item.h"
#include "ItemData_.generated.h"

USTRUCT(BlueprintType)
struct LABYRINTH117_API FItemData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
		int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
		FText name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
		uint8 itemCategory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
		FText description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
		bool isUsableInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
		TSubclassOf<AItem> itemClass;
};

UCLASS()
class LABYRINTH117_API AItemData_ : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemData_();
};