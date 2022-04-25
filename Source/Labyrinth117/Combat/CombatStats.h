// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LevelUpData.h"
#include "CombatStats.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHealthUpdatedDelegate, int, baseHP, int, currentHP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNoHealthDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LABYRINTH117_API UCombatStats : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatStats();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) int baseHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int currentHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int atk;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int def;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable) int GetBaseHP();
	UFUNCTION(BlueprintCallable) void SetBaseHP(int baseHP_);
	UFUNCTION(BlueprintCallable) int GetCurrentHP();
	UFUNCTION(BlueprintCallable) void DamageHP(int damage);
	UFUNCTION(BlueprintCallable) void HealHP(int heal);
	UFUNCTION(BlueprintCallable) int GetAtk();
	UFUNCTION(BlueprintCallable) void SetAtk(int atk_);
	UFUNCTION(BlueprintCallable) int GetDef();
	UFUNCTION(BlueprintCallable) void SetDef(int def_);
	UFUNCTION(BlueprintCallable) FLevelUpData LevelUp(int hpIncrease, int atkIncrease, int defIncrease);
	UFUNCTION(BlueprintCallable) float GetHpPercent();

	UPROPERTY(BlueprintAssignable) FNoHealthDelegate onNoHealthDelegate;
	UPROPERTY(BlueprintAssignable) FHealthUpdatedDelegate onHealthUpdatedDelegate;
};
