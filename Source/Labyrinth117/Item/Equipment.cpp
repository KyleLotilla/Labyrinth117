// Fill out your copyright notice in the Description page of Project Settings.


#include "Equipment.h"

// Sets default values for this component's properties
UEquipment::UEquipment()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	this->armorItems.Init(nullptr, 3);
	this->armors.Init(nullptr, 3);
}


// Called when the game starts
void UEquipment::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEquipment::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEquipment::EquipWeapon(AItem* weapon_)
{
	if ((ItemCategory) weapon_->GetItemCategory() == ItemCategory::WEAPON)
	{
		TArray<UWeapon*> weaponArray;
		weapon_->GetComponents<UWeapon>(weaponArray);
		if (weaponArray.Num() > 0)
		{
			this->UnequipWeapon();
			this->weaponItem = weapon_;
			this->weaponItem->SetIsEquipped(true);
			this->weapon = weaponArray[0];
		}
	}
}

void UEquipment::UnequipWeapon()
{
	if (this->weaponItem)
	{
		this->weaponItem->SetIsEquipped(false);
	}
	this->weaponItem = nullptr;
	this->weapon = nullptr;
}

void UEquipment::EquipArmor(AItem * armor_)
{
	if ((ItemCategory) armor_->GetItemCategory() == ItemCategory::ARMOR)
	{
		TArray<UArmor*> armorArray;
		armor_->GetComponents<UArmor>(armorArray);
		if (armorArray.Num() > 0)
		{
			if (armorArray[0]->GetArmorType() < 3)
			{
				uint8 armorType = armorArray[0]->GetArmorType();
				this->UnequipArmor(armorType);
				this->armorItems[armorType] = armor_;
				this->armorItems[armorType]->SetIsEquipped(true);
				this->armors[armorType] = armorArray[0];
			}
		}
	}
}

void UEquipment::UnequipArmor(uint8 armorType)
{
	if (armorType < 3)
	{
		if (this->armorItems[armorType])
		{
			this->armorItems[armorType]->SetIsEquipped(false);
		}
		this->armorItems[armorType] = nullptr;
		this->armors[armorType] = nullptr;
	}
}

int UEquipment::GetAtk()
{
	if (this->weapon)
	{
		return this->weapon->GetAttack();
	}
	return 0;
}

int UEquipment::GetDef()
{
	int finalDef = 0;
	for (UArmor* armor : this->armors)
	{
		if (armor)
		{
			finalDef += armor->GetDefense();
		}
	}
	return finalDef;
}



