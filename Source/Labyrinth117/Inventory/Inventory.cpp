// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

// Sets default values
AInventory::AInventory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

// Called when the game starts or when spawned
void AInventory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<AItem*>& AInventory::getItems()
{
	return this->items;
}

void AInventory::AddItem(AItem* item)
{
	this->items.Add(item);
	item->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void AInventory::AddItemByID(int32 itemID)
{
	AWorldGameState* gameState = Cast<AWorldGameState>(this->GetWorld()->GetGameState());
	if (gameState)
	{
		UDataTable* itemDataTable = gameState->GetItemDataTable();
		if (itemDataTable)
		{
			FItemData* itemData = itemDataTable->FindRow<FItemData>(FName(FString::FromInt(itemID)), FString(TEXT("Item Data Table")));
			if (itemData)
			{
				AItem* item = GetWorld()->SpawnActor<AItem>(itemData->itemClass, this->GetActorLocation(), this->GetActorRotation());
				item->SetItemId(itemData->id);
				item->SetName(itemData->name);
				item->SetItemCategory(itemData->itemCategory);
				item->SetDescription(itemData->description);
				item->SetIsUsableInventory(itemData->isUsableInventory);

				if ((ItemCategory) itemData->itemCategory == ItemCategory::WEAPON)
				{
					UDataTable* weaponDataTable = gameState->GetWeaponDataTable();
					if (weaponDataTable)
					{
						TArray<UWeapon*> weaponArray;
						item->GetComponents<UWeapon>(weaponArray);
						FWeaponData* weaponData = weaponDataTable->FindRow<FWeaponData>(FName(FString::FromInt(itemID)), FString(TEXT("Weapon Data Table")));

						if (weaponArray.Num() > 0 && weaponData)
						{
							weaponArray[0]->SetWeaponData(*(weaponData));
						}
					}
				}
				else if ((ItemCategory)itemData->itemCategory == ItemCategory::ARMOR)
				{
					UDataTable* armorDataTable = gameState->GetArmorDataTable();
					if (armorDataTable)
					{
						TArray<UArmor*> armorArray;
						item->GetComponents<UArmor>(armorArray);
						FArmorData* armorData = armorDataTable->FindRow<FArmorData>(FName(FString::FromInt(itemID)), FString(TEXT("Weapon Data Table")));

						if (armorArray.Num() > 0 && armorData)
						{
							armorArray[0]->SetArmorData(*(armorData));
						}
					}
				}

				this->AddItem(item);
			}
		}
	}
}

AItem * AInventory::GetItem(int index)
{
	if (index < this->items.Num())
	{
		return this->items[index];
	}
	return nullptr;
}

AItem * AInventory::PopItem(int index)
{
	if (index < this->items.Num())
	{
		AItem* item = this->items[index];
		item->DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
		this->items.RemoveAt(index);
		return item;
	}
	return nullptr;
}

void AInventory::RemoveItem(int index)
{
	if (index < this->items.Num())
	{
		this->items[index]->Destroy();
		this->items.RemoveAt(index);
	}
}

bool AInventory::IsEmpty()
{
	return this->items.Num() > 0;
}
