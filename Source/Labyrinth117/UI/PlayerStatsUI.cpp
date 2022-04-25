// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatsUI.h"

void UPlayerStatsUI::SetPlayerCombatStats(UCombatStats* combatStats) 
{
	this->baseHP->SetText(FText::FromString(FString::FromInt(combatStats->GetBaseHP())));
	this->currentHP->SetText(FText::FromString(FString::FromInt(combatStats->GetCurrentHP())));
	this->healthBar->SetPercent(combatStats->GetHpPercent());
}

void UPlayerStatsUI::SetPlayerLevelStats(ULevelStats * levelStats)
{
	this->level->SetText(FText::FromString(FString::FromInt(levelStats->GetLevel())));
	this->currentExp->SetText(FText::FromString(FString::FromInt(levelStats->GetCurrentExp())));
	this->expToLevelUp->SetText(FText::FromString(FString::FromInt(levelStats->GetExpToLevelUp())));
	this->expBar->SetPercent(levelStats->GetExpPercent());
}

void UPlayerStatsUI::SetAtk(int atk_)
{
	this->atk->SetText(FText::FromString(FString::FromInt(atk_)));
}

void UPlayerStatsUI::SetDef(int def_)
{
	this->def->SetText(FText::FromString(FString::FromInt(def_)));
}