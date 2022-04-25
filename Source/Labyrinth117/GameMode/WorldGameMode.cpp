// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldGameMode.h"

void AWorldGameMode::BindToPlayerCombatStats()
{
	UWorld* world = this->GetWorld();
	if (world)
	{
		APlayerController* controller = world->GetFirstPlayerController();
		if (controller)
		{
			APlayerWorldPawn* pawn = controller->GetPawn<APlayerWorldPawn>();
			if (pawn)
			{
				UCombatStats* combatStats = pawn->GetPlayerCombatStats();
				if (combatStats)
				{
					combatStats->onNoHealthDelegate.AddDynamic(this, &AWorldGameMode::LoseGame);
				}
			}
		}
	}
}

void AWorldGameMode::WinGame()
{
	UWorld* world = this->GetWorld();
	if (world)
	{
		APlayerWorldController* controller = Cast<APlayerWorldController>(world->GetFirstPlayerController());
		if (controller)
		{
			controller->LoadPauseMenuUI(FName(TEXT("WIN_GAME")));
			APawn* pawn = controller->GetPawn();
			if (pawn)
			{
				controller->UnPossess();
				pawn->Destroy();
			}
		}
	}
}

void AWorldGameMode::LoseGame()
{
	UWorld* world = this->GetWorld();
	if (world)
	{
		APlayerWorldController* controller = Cast<APlayerWorldController>(world->GetFirstPlayerController());
		if (controller)
		{
			controller->LoadPauseMenuUI(FName(TEXT("LOSE_GAME")));
			APawn* pawn = controller->GetPawn();
			if (pawn)
			{
				controller->UnPossess();
				pawn->Destroy();
			}
		}
	}
}
