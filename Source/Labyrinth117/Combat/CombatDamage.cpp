// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatDamage.h"

// Sets default values for this component's properties
UCombatDamage::UCombatDamage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UCombatDamage::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCombatDamage::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int UCombatDamage::GetDamage()
{
	return this->damage;
}

void UCombatDamage::SetDamage(int damage_)
{
	this->damage = damage_;
}

