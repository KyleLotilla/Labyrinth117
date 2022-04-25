// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Item/Item.h"
#include "../Item/ItemData_.h"
#include "../Item/Weapon.h"
#include "../Item/WeaponData_.h"
#include "../Item/Armor.h"
#include "../Item/ArmorData_.h"
#include "../Item/ItemCategory.h"
#include "../GameMode/WorldGameState.h"
#include "Engine/DataTable.h"
#include "Inventory.generated.h"

UCLASS()
class LABYRINTH117_API AInventory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Inventory Function")
		TArray<AItem*>& getItems();
	UFUNCTION(BlueprintCallable, Category = "Inventory Function")
		void AddItem(AItem* item);
	UFUNCTION(BlueprintCallable, Category = "Inventory Function")
		void AddItemByID(int32 itemID);
	UFUNCTION(BlueprintCallable, Category = "Inventory Function")
		AItem* GetItem(int index);
	UFUNCTION(BlueprintCallable, Category = "Inventory Function")
		AItem* PopItem(int index);
	UFUNCTION(BlueprintCallable, Category = "Inventory Function")
		void RemoveItem(int index);
	UFUNCTION(BlueprintCallable, Category = "Inventory Function")
		bool IsEmpty();

private:
	UPROPERTY(EditAnywhere) TArray<AItem*> items;
};
