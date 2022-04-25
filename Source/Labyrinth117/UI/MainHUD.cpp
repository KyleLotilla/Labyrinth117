// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"

void UMainHUD::UpdateHealth(int baseHP, int currentHP)
{
	this->baseHPText->SetText(FText::FromString(FString::FromInt(baseHP)));
	this->currentHPText->SetText(FText::FromString(FString::FromInt(currentHP)));
	float hpPercent = (float)currentHP / (float)baseHP;
	this->healthBar->SetPercent(hpPercent);
}
