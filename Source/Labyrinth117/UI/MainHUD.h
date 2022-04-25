// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "../Combat/LevelStats.h"
#include "Components/TextBlock.h"
#include "../Combat/LevelUpData.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API UMainHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void UpdateHealth(int baseHP, int currentHP);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UProgressBar* healthBar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UTextBlock* baseHPText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UTextBlock* currentHPText;
};
