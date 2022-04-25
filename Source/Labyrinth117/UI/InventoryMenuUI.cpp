// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryMenuUI.h"

void UInventoryMenuUI::RefreshMenu()
{
	this->inventoryList->ReloadList();
	this->itemDetails->ClearDetails();
}

void UInventoryMenuUI::SetInventory(AInventory* inventory_) 
{
	this->inventory = inventory_;
	this->inventoryList->SetInventory(inventory_);
}