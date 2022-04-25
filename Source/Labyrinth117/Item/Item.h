// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS(BlueprintType)
class LABYRINTH117_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Item Function") int32 GetItemId();
	UFUNCTION(BlueprintCallable, Category = "Item Function") void SetItemId(int32 itemId_);
	UFUNCTION(BlueprintCallable, Category = "Item Function") FText GetName();
	UFUNCTION(BlueprintCallable, Category = "Item Function") void SetName(FText name_);
	UFUNCTION(BlueprintCallable, Category = "Item Function") uint8 GetItemCategory();
	UFUNCTION(BlueprintCallable, Category = "Item Function") void SetItemCategory(uint8 itemCategory_);
	UFUNCTION(BlueprintCallable, Category = "Item Function") FText GetDescription();
	UFUNCTION(BlueprintCallable, Category = "Item Function") void SetDescription(FText description_);
	UFUNCTION(BlueprintCallable, Category = "Item Function") bool IsUsableInventory();
	UFUNCTION(BlueprintCallable, Category = "Item Function") void SetIsUsableInventory(bool isUsableInventory__);
	UFUNCTION(BlueprintCallable, Category = "Item Function") bool IsEquipped();
	UFUNCTION(BlueprintCallable, Category = "Item Function") void SetIsEquipped(bool isEquipped__);

private:
	UPROPERTY(EditAnywhere, Category = "Item Data")
		int32 itemId;

	UPROPERTY(EditAnywhere, Category = "Item Data")
		FText name;

	UPROPERTY(EditAnywhere, Category = "Item Data")
		uint8 itemCategory;

	UPROPERTY(EditAnywhere, Category = "Item Data")
		FText description;

	UPROPERTY(EditAnywhere, Category = "Item Data")
		bool isUsableInventory_;

	UPROPERTY(EditAnywhere, Category = "Item Data")
		bool isEquipped_;
};
