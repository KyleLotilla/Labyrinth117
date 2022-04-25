// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Blueprint/UserWidget.h" 
#include "PauseMenuUIData.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct LABYRINTH117_API FPauseMenuUIData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UUserWidget> pauseMenuClass;
};
