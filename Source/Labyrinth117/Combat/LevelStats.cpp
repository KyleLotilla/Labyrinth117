// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelStats.h"

// Sets default values for this component's properties
ULevelStats::ULevelStats()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void ULevelStats::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void ULevelStats::LevelUp()
{
	this->levelUpData = this->combatStats->LevelUp(this->HP_LEVEL_UP_INCREASE, this->ATK_LEVEL_UP_INCREASE, this->DEF_LEVEL_UP_INCREASE);
	this->levelUpData.prevLevel = this->level;

	this->currentExp = this->expToLevelUp - this->currentExp;
	this->level++;
	this->expToLevelUp = this->expToLevelUp * this->EXP_LEVEL_UP_MULTIPLIER;

	this->levelUpData.currLevel = this->level;
	onLevelUpDelegate.Broadcast(this->levelUpData);
}

// Called every frame
void ULevelStats::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int ULevelStats::GetLevel()
{
	return this->level;
}

void ULevelStats::SetLevel(int level_)
{
	this->level = level_;
}

FLevelUpData ULevelStats::GetLevelUpData()
{
	return this->levelUpData;
}

void ULevelStats::GainExp(int exp)
{
	this->currentExp += exp;
	if (this->currentExp >= this->expToLevelUp)
	{
		this->LevelUp();
	}
}

void ULevelStats::SetCombatStats(UCombatStats* combatStats_)
{
	this->combatStats = combatStats_;
}

int ULevelStats::GetCurrentExp()
{
	return this->currentExp;
}

int ULevelStats::GetExpToLevelUp()
{
	return this->expToLevelUp;
}

float ULevelStats::GetExpPercent() 
{
	return (float) (this->currentExp) / (float) (this->expToLevelUp);
}