// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WeaponData_.generated.h"

USTRUCT(BlueprintType)
struct LABYRINTH117_API FWeaponData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
		int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
		uint8 weaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Data")
		int32 attack;

};

UCLASS()
class LABYRINTH117_API AWeaponData_ : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeaponData_();
};