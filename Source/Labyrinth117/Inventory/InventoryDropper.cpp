// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryDropper.h"

// Sets default values for this component's properties
UInventoryDropper::UInventoryDropper()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UInventoryDropper::DropInventory()
{
	TArray<int32> droppedItems;
	for (FDropRate& dropRate : dropTable)
	{
		int32 roll = FMath::RandRange(1, 100);
		if (roll <= dropRate.dropRate)
		{
			droppedItems.Add(dropRate.id);
		}
	}

	if (droppedItems.Num() > 0)
	{
		AActor* owner = this->GetOwner();
		FVector spawnLocation = owner->GetActorLocation() + this->spawnOffset;
		AInventory* inventory = GetWorld()->SpawnActor<AInventory>(this->inventoryClass, spawnLocation, owner->GetActorRotation());
		for (int32 itemID : droppedItems)
		{
			inventory->AddItemByID(itemID);
		}
	}
}

// Called when the game starts
void UInventoryDropper::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryDropper::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

