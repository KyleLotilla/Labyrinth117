// Fill out your copyright notice in the Description page of Project Settings.


#include "GetItemButtonUI.h"

void UGetItemButtonUI::SetSourceInventory(AInventory* sourceInventory_)
{
	this->sourceInventory = sourceInventory_;
}

void UGetItemButtonUI::SetPlayerInventory(AInventory * playerInventory_)
{
	this->playerInventory = playerInventory_;
}

void UGetItemButtonUI::SetSelectedIndex(int32 selectedIndex_)
{
	this->selectedIndex = selectedIndex_;
	this->SetIsEnabled(true);
}

void UGetItemButtonUI::GetItem()
{
	if (this->sourceInventory && this->playerInventory && this->selectedIndex >= 0)
	{
		AItem* item = this->sourceInventory->PopItem(this->selectedIndex);
		if (item)
		{
			this->playerInventory->AddItem(item);
		}
		this->ClearIndex();
	}
}

void UGetItemButtonUI::ClearIndex()
{
	this->selectedIndex = -1;
	this->SetIsEnabled(false);
}
