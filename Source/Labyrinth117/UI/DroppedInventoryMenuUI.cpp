// Fill out your copyright notice in the Description page of Project Settings.


#include "DroppedInventoryMenuUI.h"

void UDroppedInventoryMenuUI::SetSourceInventory(AInventory* inventory)
{
	this->sourceInventory = inventory;
	this->inventoryMenu->SetInventory(inventory);
	this->getItemButton->SetSourceInventory(inventory);
}

void UDroppedInventoryMenuUI::SetPlayerInventory(AInventory* inventory)
{
	this->playerInventory = inventory;
	this->getItemButton->SetPlayerInventory(inventory);
}

void UDroppedInventoryMenuUI::RefreshMenu() 
{
	this->inventoryMenu->RefreshMenu();
	this->getItemButton->ClearIndex();
}