// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

// Sets default values for this component's properties
UWeapon::UWeapon()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UWeapon::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeapon::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeapon::SetWeaponData(FWeaponData weaponData)
{
	this->weaponType = weaponData.weaponType;
	this->attack = weaponData.attack;
}

uint8 UWeapon::GetWeaponType()
{
	return 	this->weaponType;
}

int32 UWeapon::GetAttack()
{
	return this->attack;
}

