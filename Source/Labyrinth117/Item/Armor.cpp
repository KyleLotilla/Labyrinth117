// Fill out your copyright notice in the Description page of Project Settings.


#include "Armor.h"

// Sets default values for this component's properties
UArmor::UArmor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UArmor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UArmor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UArmor::SetArmorData(FArmorData armorData)
{
	this->armorType = armorData.armorType;
	this->defense = armorData.defense;
}

uint8 UArmor::GetArmorType()
{
	return this->armorType;
}

int32 UArmor::GetDefense()
{
	return this->defense;
}


