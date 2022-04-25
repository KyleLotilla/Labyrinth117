// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipItemButtonUI.h"

void UEquipItemButtonUI::EquipSelectedItem()
{
	if (this->selectedItem && this->playerEquipment)
	{
		uint8 itemCategory = this->selectedItem->GetItemCategory();

		if ((ItemCategory)itemCategory == ItemCategory::WEAPON)
		{
			this->playerEquipment->EquipWeapon(this->selectedItem);
			onItemEquippedDelegate.Broadcast();
		}
		else if ((ItemCategory)itemCategory == ItemCategory::ARMOR)
		{
			this->playerEquipment->EquipArmor(this->selectedItem);
			onItemEquippedDelegate.Broadcast();
		}
	}
}

void UEquipItemButtonUI::SetItem(AItem * item)
{
	this->selectedItem = item;
}

void UEquipItemButtonUI::SetPlayerEquipment(UEquipment * playerEquipment_)
{
	this->playerEquipment = playerEquipment_;
}

void UEquipItemButtonUI::ClearItem()
{
	this->selectedItem = nullptr;
}
