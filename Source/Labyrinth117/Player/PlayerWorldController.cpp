// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWorldController.h"

void APlayerWorldController::BeginPlay()
{
	Super::BeginPlay();
	this->LoadPauseMenuUIDataTable();
	if (!(this->hasPlayed))
	{
		this->LoadPauseMenuUI(FName(TEXT("TUTORIAL")));
	}
}

void APlayerWorldController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	this->worldPawn = Cast<APlayerWorldPawn>(InPawn);

	if (this->worldPawn)
	{
		UCombatStats* combatStats = this->worldPawn->GetPlayerCombatStats();
		if (combatStats)
		{
			this->mainHUD = CreateWidget<UMainHUD>(this, this->mainHUDClass);
			if (this->mainHUD)
			{
				this->LoadHUD();
				mainHUD->UpdateHealth(combatStats->GetBaseHP(), combatStats->GetCurrentHP());
				combatStats->onHealthUpdatedDelegate.AddDynamic(this->mainHUD, &UMainHUD::UpdateHealth);
			}
		}
	}
}

void APlayerWorldController::OnUnPossess()
{
	this->worldPawn = nullptr;
}

void APlayerWorldController::SetMoveAxisValueX(float axisValue)
{
	if (this->worldPawn)
	{
		this->worldPawn->SetMoveAxisValueX(axisValue);
	}
}

void APlayerWorldController::SetMoveAxisValueY(float axisValue)
{
	if (this->worldPawn)
	{
		this->worldPawn->SetMoveAxisValueY(axisValue);
	}
}

void APlayerWorldController::SetLookAxisValueX(float axisValue)
{
	if (this->worldPawn)
	{
		this->worldPawn->SetLookAxisValueX(axisValue);
	}
}

void APlayerWorldController::SetLookAxisValueY(float axisValue)
{
	if (this->worldPawn)
	{
		this->worldPawn->SetLookAxisValueY(axisValue);
	}
}

void APlayerWorldController::FireProjectile()
{
	if (this->worldPawn)
	{
		this->worldPawn->FireProjectile();
	}
}

void APlayerWorldController::InteractObject()
{
	if (this->worldPawn)
	{
		UCameraComponent* camera = this->worldPawn->GetPlayerCamera();

		if (camera)
		{
			this->LineTraceFromCamera(camera);

			if (this->outHit.bBlockingHit)
			{
				AActor* hitActor = this->outHit.GetActor();
				if (hitActor->ActorHasTag(FName("INTERACTABLE")))
				{
					TArray<UInteractableWorldObject*> interactableObjects;
					hitActor->GetComponents<UInteractableWorldObject>(interactableObjects);

					for (UInteractableWorldObject* interactableObject : interactableObjects)
					{
						interactableObject->OnInteractedWithPlayer();
					}
				}
				this->outHit.bBlockingHit = false;
			}
		}
	}
}

void APlayerWorldController::LineTraceFromCamera(UCameraComponent* camera)
{
	FVector start = camera->GetComponentLocation();
	FVector fowardVector = camera->GetForwardVector();
	FVector end = ((fowardVector * this->LINE_TRACE_RANGE) + start);
	FCollisionQueryParams collisionParams;

	GetWorld()->LineTraceSingleByChannel(this->outHit, start, end, ECC_Visibility, collisionParams);
}

void APlayerWorldController::LoadPauseMenuUIDataTable()
{
	this->pauseMenuUIDataTable = LoadObject<UDataTable>(NULL, this->PAUSE_MENU_UI_DATA_TABLE_LOCATION);
}

UUserWidget* APlayerWorldController::LoadPauseMenuUI(FName pauseMenuName)
{
	FPauseMenuUIData* pauseMenuUIData = this->pauseMenuUIDataTable->FindRow<FPauseMenuUIData>(pauseMenuName, FString(TEXT("Pause Menu UI Data Table")));
	if (pauseMenuUIData)
	{
		this->currentPauseMenu = CreateWidget<UUserWidget>(this, pauseMenuUIData->pauseMenuClass);
		if (this->currentPauseMenu)
		{
			if (this->mainHUD)
			{
				this->mainHUD->RemoveFromParent();
			}
			FInputModeUIOnly mode;
			this->SetInputMode(mode);
			this->bShowMouseCursor = true;
			this->SetPause(true);
			this->currentPauseMenu->AddToViewport(9999);
		}
		return this->currentPauseMenu;
	}
	return nullptr;
}

void APlayerWorldController::LoadHUD()
{
	if (this->currentPauseMenu)
	{
		this->currentPauseMenu->RemoveFromParent();
	}
	FInputModeGameOnly mode;
	this->SetInputMode(mode);
	this->bShowMouseCursor = false;
	this->SetPause(false);
	this->mainHUD->AddToViewport(999);
}
