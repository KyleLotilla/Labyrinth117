// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	this->isEquipped_ = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AItem::GetItemId()
{
	return this->itemId;
}

void AItem::SetItemId(int32 itemId_)
{
	this->itemId = itemId_;
}

FText AItem::GetName()
{
	return this->name;
}

void AItem::SetName(FText name_)
{
	this->name = name_;
}

uint8 AItem::GetItemCategory()
{
	return this->itemCategory;
}

void AItem::SetItemCategory(uint8 itemCategory_)
{
	this->itemCategory = itemCategory_;
}

FText AItem::GetDescription()
{
	return this->description;
}

void AItem::SetDescription(FText description_)
{
	this->description = description_;
}

bool AItem::IsUsableInventory()
{
	return this->isUsableInventory_;
}

void AItem::SetIsUsableInventory(bool isUsableInventory__)
{
	this->isUsableInventory_ = isUsableInventory__;
}

bool AItem::IsEquipped()
{
	return this->isEquipped_;
}

void AItem::SetIsEquipped(bool isEquipped__)
{
	this->isEquipped_ = isEquipped__;
}

