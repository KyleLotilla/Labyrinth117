// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableWorldInventory.h"

void UInteractableWorldInventory::OnInteractedWithPlayer()
{
	APlayerWorldController* controller = Cast<APlayerWorldController>(this->GetWorld()->GetFirstPlayerController());
	APlayerWorldPawn* pawn = controller->GetPawn<APlayerWorldPawn>();
	AInventory* playerInventory = pawn->GetPlayerInventory();

	if (this->sourceInventory && playerInventory && controller)
	{
		UUserWidget* droppedInventoryMenuWidget = controller->LoadPauseMenuUI(FName(TEXT("DROPPED_INVENTORY")));
		if (droppedInventoryMenuWidget)
		{
			UDroppedInventoryMenuUI* droppedInventoryMenu = Cast<UDroppedInventoryMenuUI>(droppedInventoryMenuWidget);
			if (droppedInventoryMenu)
			{
				droppedInventoryMenu->SetSourceInventory(this->sourceInventory);
				droppedInventoryMenu->SetPlayerInventory(playerInventory);
			}
			onOpenWorldInventoryDelegate.Broadcast();
		}
	}
}

void UInteractableWorldInventory::SetSourceInventory(AInventory* sourceInventory_)
{
	this->sourceInventory = sourceInventory_;
}