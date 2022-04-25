// Fill out your copyright notice in the Description page of Project Settings.


#include "ExpGiver.h"

// Sets default values for this component's properties
UExpGiver::UExpGiver()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UExpGiver::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UExpGiver::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UExpGiver::GiveExp()
{
	UWorld* world = this->GetWorld();
	if (world)
	{
		APlayerController* controller = world->GetFirstPlayerController();
		if (controller)
		{
			APlayerWorldPawn* pawn = Cast<APlayerWorldPawn>(controller->GetPawn());
			if (pawn)
			{
				ULevelStats* levelStats = pawn->GetPlayerLevelStats();
				if (levelStats)
				{
					levelStats->GainExp(this->exp);
				}
			}
		}
		
	}
}

