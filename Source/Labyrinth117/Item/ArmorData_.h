// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "ArmorData_.generated.h"


USTRUCT(BlueprintType)
struct LABYRINTH117_API FArmorData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Armor Data")
		int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Armor Data")
		uint8 armorType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Armor Data")
		int32 defense;

};

UCLASS()
class LABYRINTH117_API AArmorData_ : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArmorData_();
};
