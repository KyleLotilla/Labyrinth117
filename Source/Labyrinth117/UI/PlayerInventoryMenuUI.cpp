// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInventoryMenuUI.h"

void UPlayerInventoryMenuUI::SetInventory(AInventory* inventory_) 
{
	this->inventory = inventory_;
	this->inventoryMenu->SetInventory(inventory_);
	this->itemActionUI->SetPlayerInventory(inventory_);
}

void UPlayerInventoryMenuUI::SetEquipment(UEquipment * equipment_)
{
	this->equipment = equipment_;
	this->itemActionUI->SetPlayerEquipment(equipment_);
}

void UPlayerInventoryMenuUI::RefreshMenu()
{
	this->inventoryMenu->RefreshMenu();
	this->itemActionUI->ClearUI();
}
