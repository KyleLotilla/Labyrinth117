// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory.h"
#include "InventoryDropper.generated.h"


USTRUCT(Blueprintable)
struct FDropRate
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 dropRate;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LABYRINTH117_API UInventoryDropper : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryDropper();
	UFUNCTION(BlueprintCallable) void DropInventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FDropRate> dropTable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AInventory> inventoryClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector spawnOffset;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
