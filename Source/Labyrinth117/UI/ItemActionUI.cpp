// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemActionUI.h"

void UItemActionUI::SetPlayerEquipment(UEquipment * playerEquipment_)
{
	this->playerEquipment = playerEquipment_;
}

void UItemActionUI::SetPlayerInventory(AInventory * playerInventory_)
{
	this->playerInventory = playerInventory_;
}

void UItemActionUI::ItemSelected(AItem* item, int index)
{
	this->ClearUI();
	uint8 itemCategory = item->GetItemCategory();

	if ((ItemCategory)itemCategory == ItemCategory::WEAPON || (ItemCategory)itemCategory == ItemCategory::ARMOR)
	{
		UEquipItemButtonUI* equipItemButtonUI = CreateWidget<UEquipItemButtonUI>(this, this->equipItemButtonClass);
		equipItemButtonUI->SetPlayerEquipment(this->playerEquipment);
		equipItemButtonUI->SetItem(item);
		equipItemButtonUI->onItemEquippedDelegate.AddDynamic(this, &UItemActionUI::OnItemAction);
		UHorizontalBoxSlot* boxSlot = box->AddChildToHorizontalBox(equipItemButtonUI);
		FSlateChildSize sizeRule;
		sizeRule.SizeRule = ESlateSizeRule::Fill;
		boxSlot->SetSize(sizeRule);
	}
	else if ((ItemCategory)itemCategory == ItemCategory::CONSUMABLE)
	{
		UUseConsumableButtonUI* useConsumableButtonUI = CreateWidget<UUseConsumableButtonUI>(this, this->useConsumableButtonClass);
		useConsumableButtonUI->SetPlayerInventory(this->playerInventory);
		useConsumableButtonUI->SetSelectedIndex(index);
		useConsumableButtonUI->onItemConsumedDelegate.AddDynamic(this, &UItemActionUI::OnItemAction);
		UHorizontalBoxSlot* boxSlot = box->AddChildToHorizontalBox(useConsumableButtonUI);
		FSlateChildSize sizeRule;
		sizeRule.SizeRule = ESlateSizeRule::Fill;
		boxSlot->SetSize(sizeRule);
	}
}

void UItemActionUI::ClearUI()
{
	box->ClearChildren();
}

void UItemActionUI::OnItemAction()
{
	onItemActionDelegate.Broadcast();
}