// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingItem.h"

void UHealingItem::UseItem()
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
					combatStats->HealHP(this->healingAmount);
				}
			}
		}
	}
}