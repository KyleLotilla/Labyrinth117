// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemDetailsUI.h"

void UItemDetailsUI::ClearDetails()
{
	this->itemName->SetText(FText::FromString(""));
	this->equipped->SetText(FText::FromString(""));
	this->itemStats->SetText(FText::FromString(""));
	this->itemDescription->SetText(FText::FromString(""));
}

void UItemDetailsUI::SetItem(AItem * item)
{
	this->ClearDetails();

	this->itemName->SetText(item->GetName());
	this->itemDescription->SetText(item->GetDescription());

	ItemCategory itemCategory = (ItemCategory) item->GetItemCategory();

	if (itemCategory == ItemCategory::WEAPON)
	{
		if (item->IsEquipped())
		{
			this->equipped->SetText(FText::FromString("Equipped"));
		}

		TArray<UWeapon*> weaponArray;
		item->GetComponents<UWeapon>(weaponArray);

		UWeapon* weapon = weaponArray[0];
		FString itemStatsString = FString("ATK: ");
		itemStatsString.Append(FString::FromInt(weapon->GetAttack()));
		this->itemStats->SetText(FText::FromString(itemStatsString));
	}
	else if (itemCategory == ItemCategory::ARMOR)
	{
		if (item->IsEquipped())
		{
			this->equipped->SetText(FText::FromString("Equipped"));
		}

		TArray<UArmor*> armorArray;
		item->GetComponents<UArmor>(armorArray);

		UArmor* armor = armorArray[0];
		FString itemStatsString = FString("Type: ");
		itemStatsString.Append(armorTypeNames[armor->GetArmorType()]);
		itemStatsString.Append(FString(" DEF: "));
		itemStatsString.Append(FString::FromInt(armor->GetDefense()));
		this->itemStats->SetText(FText::FromString(itemStatsString));
	}
}
