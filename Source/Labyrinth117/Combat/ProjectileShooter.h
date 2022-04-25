// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h" 
#include "Camera/CameraComponent.h"
#include "Projectile.h"
#include "ProjectileShooter.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LABYRINTH117_API UProjectileShooter : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UProjectileShooter();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EDitAnywhere, BlueprintReadWrite) int damage;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void FireProjectile();
	void SetDamage(int damage_);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector projectileOffset;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AProjectile> projectileClass;

private:
	UPROPERTY(VisibleAnywhere)
		float ticks = 0.0f;

	UPROPERTY(EditAnywhere)
		float fireRate;
};
