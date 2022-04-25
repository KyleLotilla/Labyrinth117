// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h" 
#include "CombatDamage.h"
#include "Projectile.generated.h"

UCLASS()
class LABYRINTH117_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) int damage;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void FireInDirection(const FVector& shootDirection);
	UFUNCTION(BlueprintCallable) int GetDamage();
	UFUNCTION(BlueprintCallable) void SetDamage(int damage_);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* projectileMovementComponent;
};
