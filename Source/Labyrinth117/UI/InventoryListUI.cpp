// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryListUI.h"

void UInventoryListUI::ReloadList()
{
	gridPanel->ClearChildren();
	if (this->inventory) 
	{
		TArray<AItem*>& items = this->inventory->getItems();

		for (int i = 0; i < items.Num(); i++)
		{
			UItemRowUI* itemRow = CreateWidget<UItemRowUI>(this, itemRowUIClass);
			itemRow->SetItem(items[i]);
			itemRow->SetIndex(i);
			itemRow->onItemRowSelectionDelegate.AddDynamic(this, &UInventoryListUI::OnItemRowSelected);
			gridPanel->AddChildToGrid(itemRow, i, 0);
		}
	}
}

void UInventoryListUI::SetInventory(AInventory* inventory_)
{
	this->inventory = inventory_;
	this->ReloadList();
}

void UInventoryListUI::OnItemRowSelected(AItem * item, int32 index)
{
	onItemRowSelectionDelegate.Broadcast(item, index);
}
