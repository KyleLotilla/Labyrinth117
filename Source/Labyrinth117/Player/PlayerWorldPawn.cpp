// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWorldPawn.h"

// Sets default values
APlayerWorldPawn::APlayerWorldPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerWorldPawn::BeginPlay()
{
	Super::BeginPlay();
	this->invisibilityTicks = INVISIBILITY_TIME;
	this->regenTicks = REGEN_RATE;
}

// Called every frame
void APlayerWorldPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->invisibilityTicks += DeltaTime;
	this->regenTicks += DeltaTime;
	if (regenTicks >= REGEN_RATE && this->playerCombatStats)
	{
		this->playerCombatStats->HealHP(1);
		regenTicks = 0.0f;
	}

	if (this->IsPawnControlled())
	{
		MoveX(DeltaTime);
		MoveY(DeltaTime);
		LookX(DeltaTime);
		LookY(DeltaTime);

		if (this->moveAxisValueX > 0.0f || this->moveAxisValueY > 0.0f)
		{
			this->onMoveDelegate.Broadcast();
		}
	}
}

// Called to bind functionality to input
void APlayerWorldPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerWorldPawn::SetMoveAxisValueX(float axisValue)
{
	this->moveAxisValueX = axisValue;
}

void APlayerWorldPawn::SetMoveAxisValueY(float axisValue)
{
	this->moveAxisValueY = axisValue;
}

void APlayerWorldPawn::SetLookAxisValueX(float axisValue)
{
	this->lookAxisValueX = axisValue;
}

void APlayerWorldPawn::SetLookAxisValueY(float axisValue)
{
	this->lookAxisValueY = axisValue;
}

void APlayerWorldPawn::MoveX(float DeltaTime)
{
	if (moveAxisValueX != 0.0f) {
		FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
		this->AddMovementInput(direction, moveAxisValueX);
	}
}

void APlayerWorldPawn::MoveY(float DeltaTime)
{
	if (moveAxisValueY != 0.0f) {
		FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
		this->AddMovementInput(direction, moveAxisValueY);
	}
}

void APlayerWorldPawn::LookX(float DeltaTime)
{
	if (lookAxisValueX != 0.0f) {
		FRotator rotation = this->GetControlRotation();
		rotation.Yaw = rotation.Yaw + lookAxisValueX;
		this->GetController()->SetControlRotation(rotation);
	}
}

void APlayerWorldPawn::LookY(float DeltaTime)
{
	if (lookAxisValueY != 0.0f) {
		FRotator rotation = this->GetControlRotation();
		rotation.Pitch = rotation.Pitch + lookAxisValueY * -1.0f;
		this->GetController()->SetControlRotation(rotation);
	}
}

void APlayerWorldPawn::FireProjectile()
{
	int finalDamage = this->GetPlayerAtk();
	this->projectileShooter->SetDamage(finalDamage);
	this->projectileShooter->FireProjectile();
	this->onProjectileFiredDelegate.Broadcast();
}

void APlayerWorldPawn::DamagePlayer(int damage)
{
	if (this->invisibilityTicks >= INVISIBILITY_TIME)
	{
		int finalDamage = damage - this->GetPlayerDef();
		if (finalDamage <= 0)
		{
			finalDamage = 1;
		}
		this->playerCombatStats->DamageHP(finalDamage);
		this->regenTicks = 0.0f;
		this->invisibilityTicks = 0.0f;
		this->onPlayerDamagedDelegate.Broadcast();
	}
		
}

int APlayerWorldPawn::GetPlayerAtk()
{
	return this->playerCombatStats->GetAtk() + this->playerEquipment->GetAtk();
}

int APlayerWorldPawn::GetPlayerDef()
{
	return this->playerCombatStats->GetDef() + this->playerEquipment->GetDef();
}

UCameraComponent * APlayerWorldPawn::GetPlayerCamera()
{
	return this->playerCamera;
}

AInventory * APlayerWorldPawn::GetPlayerInventory()
{
	return this->playerInventory;
}

UEquipment * APlayerWorldPawn::GetPlayerEquipment()
{
	return this->playerEquipment;
}

UCombatStats * APlayerWorldPawn::GetPlayerCombatStats()
{
	return this->playerCombatStats;
}

ULevelStats * APlayerWorldPawn::GetPlayerLevelStats()
{
	return this->playerLevelStats;
}
