// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelUpUI.h"

void ULevelUpUI::SetLevelUpData(FLevelUpData levelUpData) 
{
	this->prevLevel->SetText(FText::FromString(FString::FromInt(levelUpData.prevLevel)));
	this->prevHP->SetText(FText::FromString(FString::FromInt(levelUpData.prevHP)));
	this->prevAtk->SetText(FText::FromString(FString::FromInt(levelUpData.prevAtk)));
	this->prevDef->SetText(FText::FromString(FString::FromInt(levelUpData.prevDef)));

	this->currLevel->SetText(FText::FromString(FString::FromInt(levelUpData.currLevel)));
	this->currHP->SetText(FText::FromString(FString::FromInt(levelUpData.currHP)));
	this->currAtk->SetText(FText::FromString(FString::FromInt(levelUpData.currAtk)));
	this->currDef->SetText(FText::FromString(FString::FromInt(levelUpData.currDef)));
}
