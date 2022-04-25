// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatStats.h"

// Sets default values for this component's properties
UCombatStats::UCombatStats()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCombatStats::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCombatStats::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int UCombatStats::GetBaseHP()
{
	return this->baseHP;
}

void UCombatStats::SetBaseHP(int baseHP_)
{
	this->baseHP = baseHP_;
}

int UCombatStats::GetCurrentHP()
{
	return this->currentHP;
}

void UCombatStats::DamageHP(int damage)
{
	this->currentHP -= damage;
	this->onHealthUpdatedDelegate.Broadcast(this->baseHP, this->currentHP);
	if (this->currentHP <= 0)
	{
		this->onNoHealthDelegate.Broadcast();
	}
}

void UCombatStats::HealHP(int heal)
{
	if (this->currentHP != this->baseHP)
	{
		this->currentHP += heal;
		if (currentHP > this->baseHP)
		{
			this->currentHP = this->baseHP;
		}
		this->onHealthUpdatedDelegate.Broadcast(this->baseHP, this->currentHP);
	}
}

int UCombatStats::GetAtk()
{
	return this->atk;
}

void UCombatStats::SetAtk(int atk_)
{
	this->atk = atk_;
}

int UCombatStats::GetDef()
{
	return this->def;
}

void UCombatStats::SetDef(int def_)
{
	this->def = def_;
}

FLevelUpData UCombatStats::LevelUp(int hpIncrease, int atkIncrease, int defIncrease)
{
	FLevelUpData levelUpData;
	levelUpData.prevHP = this->baseHP;
	levelUpData.prevAtk = this->atk;
	levelUpData.prevDef = this->def;

	this->baseHP += hpIncrease;
	this->atk += atkIncrease;
	this->def += defIncrease;

	levelUpData.currHP = this->baseHP;
	levelUpData.currAtk = this->atk;
	levelUpData.currDef = this->def;

	this->onHealthUpdatedDelegate.Broadcast(this->baseHP, this->currentHP);
	return levelUpData;
}

float UCombatStats::GetHpPercent()
{
	return (float) this->currentHP / (float)this->baseHP;
}
