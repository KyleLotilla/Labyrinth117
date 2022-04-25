// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "../Combat/ProjectileShooter.h"
#include "../Inventory/Inventory.h"
#include "../World/InteractableWorldObject.h"
#include "../Item/Equipment.h"
#include "../Combat/CombatStats.h"
#include "../Combat/LevelStats.h"
#include "PlayerWorldPawn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FProjectileFiredDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMoveDelegate); 
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerDamagedDelegate);


UCLASS()
class LABYRINTH117_API APlayerWorldPawn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerWorldPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetMoveAxisValueX(float axisValue);
	void SetMoveAxisValueY(float axisValue);
	void SetLookAxisValueX(float axisValue);
	void SetLookAxisValueY(float axisValue);
	void FireProjectile();
	UFUNCTION(BlueprintCallable) void DamagePlayer(int damage);
	UFUNCTION(BlueprintCallable) int GetPlayerAtk();
	UFUNCTION(BlueprintCallable) int GetPlayerDef();
	UCameraComponent* GetPlayerCamera();
	UFUNCTION(BlueprintCallable) AInventory* GetPlayerInventory();
	UFUNCTION(BlueprintCallable) UEquipment* GetPlayerEquipment();
	UFUNCTION(BlueprintCallable) UCombatStats* GetPlayerCombatStats();
	UFUNCTION(BlueprintCallable) ULevelStats* GetPlayerLevelStats();

	UPROPERTY(BlueprintAssignable) FProjectileFiredDelegate onProjectileFiredDelegate;
	UPROPERTY(BlueprintAssignable) FMoveDelegate onMoveDelegate;
	UPROPERTY(BlueprintAssignable) FPlayerDamagedDelegate onPlayerDamagedDelegate;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UCameraComponent* playerCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UProjectileShooter* projectileShooter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AInventory* playerInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UEquipment* playerEquipment;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UCombatStats* playerCombatStats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) ULevelStats* playerLevelStats;

	UPROPERTY(VisibleAnywhere) float invisibilityTicks;
	UPROPERTY(VisibleAnywhere) float regenTicks;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float INVISIBILITY_TIME;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float REGEN_RATE;

private:
	float moveAxisValueX = 0.0f;
	float moveAxisValueY = 0.0f;
	float lookAxisValueX = 0.0f;
	float lookAxisValueY = 0.0f;


	void MoveX(float DeltaTime);
	void MoveY(float DeltaTime);
	void LookX(float DeltaTime);
	void LookY(float DeltaTime);
};
