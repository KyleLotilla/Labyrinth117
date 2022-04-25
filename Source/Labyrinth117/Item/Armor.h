// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArmorData_.h"
#include "Armor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LABYRINTH117_API UArmor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UArmor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetArmorData(FArmorData armorData);
	UFUNCTION(BlueprintCallable, Category = "Armor Function") uint8 GetArmorType();
	UFUNCTION(BlueprintCallable, Category = "Armor Function") int32 GetDefense();
	
private:
	UPROPERTY(EditAnywhere, Category = "Armor Data")
		uint8 armorType;

	UPROPERTY(EditAnywhere, Category = "Armor Data")
		int32 defense;
		
};
