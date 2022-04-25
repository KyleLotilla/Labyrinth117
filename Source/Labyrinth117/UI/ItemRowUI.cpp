// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemRowUI.h"

void UItemRowUI::SetItem(AItem* item_) 
{
	this->item = item_;
	if (item->IsEquipped())
	{
		equipped->SetText(FText::FromString("E"));
	}
	else 
	{
		equipped->SetText(FText::FromString(""));
	}

	itemName->SetText(item->GetName());
}

void UItemRowUI::SetIndex(int32 index_)
{
	this->index = index_;
}

void UItemRowUI::ItemRowSelected()
{
	onItemRowSelectionDelegate.Broadcast(this->item, this->index);
}
