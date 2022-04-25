// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h" 
#include "Blueprint/UserWidget.h"
#include "TutorialMenuUI.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API UTutorialMenuUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void NavigatePage(int index_);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UHorizontalBox* box;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidget* backButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidget* forwardButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidget* okButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<TSubclassOf<UUserWidget>> tutorialPages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int index = 0;
};
