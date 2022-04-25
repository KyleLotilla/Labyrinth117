// Fill out your copyright notice in the Description page of Project Settings.


#include "UseConsumableButtonUI.h"

void UUseConsumableButtonUI::SetPlayerInventory(AInventory* playerInventory_) 
{
	this->playerInventory = playerInventory_;
}

void UUseConsumableButtonUI::SetSelectedIndex(int32 selectedIndex_)
{
	this->selectedIndex = selectedIndex_;
}

void UUseConsumableButtonUI::UseItem()
{
	AItem* item = this->playerInventory->PopItem(this->selectedIndex);

	if (item)
	{
		TArray<UUsableItem*> usableItemArray;
		item->GetComponents<UUsableItem>(usableItemArray);
		if (usableItemArray.Num() > 0)
		{
			usableItemArray[0]->UseItem();
			item->Destroy();
			onItemConsumedDelegate.Broadcast();
		}
	}
}
