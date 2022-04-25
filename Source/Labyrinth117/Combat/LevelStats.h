// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatStats.h"
#include "LevelStats.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLevelUpDelegate, FLevelUpData, levelUpData);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class LABYRINTH117_API ULevelStats : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULevelStats();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) int level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int expToLevelUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int currentExp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FLevelUpData levelUpData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UCombatStats* combatStats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int HP_LEVEL_UP_INCREASE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int ATK_LEVEL_UP_INCREASE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int DEF_LEVEL_UP_INCREASE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float EXP_LEVEL_UP_MULTIPLIER;
	
	UFUNCTION(BlueprintCallable) void LevelUp();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable) int GetLevel();
	UFUNCTION(BlueprintCallable) void SetLevel(int level_);
	UFUNCTION(BlueprintCallable) FLevelUpData GetLevelUpData();
	UFUNCTION(BlueprintCallable) void GainExp(int exp);
	UFUNCTION(BlueprintCallable) void SetCombatStats(UCombatStats* combatStats_);
	UFUNCTION(BlueprintCallable) int GetCurrentExp();
	UFUNCTION(BlueprintCallable) int GetExpToLevelUp();
	UFUNCTION(BlueprintCallable) float GetExpPercent();
	
	UPROPERTY(BlueprintAssignable) FLevelUpDelegate onLevelUpDelegate;
};
