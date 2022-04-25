// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraComponent.h"
#include "../UI/PauseMenuUIData.h"
#include "PlayerWorldPawn.h"
#include "Engine/DataTable.h"
#include "../UI/MainHUD.h"
#include "PlayerWorldController.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH117_API APlayerWorldController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay();
	UFUNCTION(BlueprintCallable) UUserWidget* LoadPauseMenuUI(FName pauseMenuName);
	UFUNCTION(BlueprintCallable) void LoadHUD();

protected:
	virtual void OnPossess(APawn* InPawn);
	virtual void OnUnPossess();
	UFUNCTION(BlueprintCallable) void SetMoveAxisValueX(float axisValue);
	UFUNCTION(BlueprintCallable) void SetMoveAxisValueY(float axisValue);
	UFUNCTION(BlueprintCallable) void SetLookAxisValueX(float axisValue);
	UFUNCTION(BlueprintCallable) void SetLookAxisValueY(float axisValue);
	UFUNCTION(BlueprintCallable) void FireProjectile();
	UFUNCTION(BlueprintCallable) void InteractObject();
	UFUNCTION(BlueprintCallable) void LineTraceFromCamera(UCameraComponent* camera);
	UFUNCTION(BlueprintCallable) void LoadPauseMenuUIDataTable();
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite) APlayerWorldPawn* worldPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UMainHUD* mainHUD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<UMainHUD> mainHUDClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UUserWidget* currentPauseMenu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UDataTable* pauseMenuUIDataTable;
	TCHAR* PAUSE_MENU_UI_DATA_TABLE_LOCATION = TEXT("DataTable'/Game/Datatables/PauseMenuUIDataTable.PauseMenuUIDataTable'");

	UPROPERTY(EditAnywhere) float LINE_TRACE_RANGE = 200.0f;
	FHitResult outHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool hasPlayed;
};
