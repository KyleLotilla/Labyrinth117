// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Engine/DataTable.h"
#include "WorldGameState.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API AWorldGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) UDataTable* GetItemDataTable();
	UFUNCTION(BlueprintCallable) UDataTable* GetWeaponDataTable();
	UFUNCTION(BlueprintCallable) UDataTable* GetArmorDataTable();


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UDataTable* itemDataTable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UDataTable* weaponDataTable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UDataTable* armorDataTable;

	TCHAR* ITEM_DATA_TABLE_LOCATION = TEXT("DataTable'/Game/Datatables/ItemDataTable.ItemDataTable'");
	TCHAR* WEAPON_DATA_TABLE_LOCATION = TEXT("DataTable'/Game/Datatables/WeaponDataTable.WeaponDataTable'");
	TCHAR* ARMOR_DATA_TABLE_LOCATION = TEXT("DataTable'/Game/Datatables/ArmorDataTable.ArmorDataTable'");

};
