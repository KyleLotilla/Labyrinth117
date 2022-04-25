// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "ItemCategory.h"
#include "WeaponType.h"
#include "ArmorType.h"
#include "Equipment.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LABYRINTH117_API UEquipment : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEquipment();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite) AItem* weaponItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWeapon* weapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)  TArray<AItem*> armorItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)  TArray<UArmor*> armors;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable) void EquipWeapon(AItem* weapon_);
	UFUNCTION(BlueprintCallable) void UnequipWeapon();
	UFUNCTION(BlueprintCallable) void EquipArmor(AItem* armor_);
	UFUNCTION(BlueprintCallable) void UnequipArmor(uint8 armorType);
	UFUNCTION(BlueprintCallable) int GetAtk();
	UFUNCTION(BlueprintCallable) int GetDef();
		
};
