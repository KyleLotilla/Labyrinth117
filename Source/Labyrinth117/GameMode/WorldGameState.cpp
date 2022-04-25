// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldGameState.h"

UDataTable * AWorldGameState::GetItemDataTable()
{
	if (!(this->itemDataTable))
	{
		this->itemDataTable = LoadObject<UDataTable>(NULL, this->ITEM_DATA_TABLE_LOCATION);
	}
	return this->itemDataTable;
}

UDataTable * AWorldGameState::GetWeaponDataTable()
{
	if (!(this->weaponDataTable))
	{
		this->weaponDataTable = LoadObject<UDataTable>(NULL, this->WEAPON_DATA_TABLE_LOCATION);
	}
	return this->weaponDataTable;
}

UDataTable * AWorldGameState::GetArmorDataTable()
{
	if (!(this->armorDataTable))
	{
		this->armorDataTable = LoadObject<UDataTable>(NULL, this->ARMOR_DATA_TABLE_LOCATION);
	}
	return this->armorDataTable;
}
