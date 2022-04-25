// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileShooter.h"

// Sets default values for this component's properties
UProjectileShooter::UProjectileShooter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	this->ticks = this->fireRate;
}


// Called when the game starts
void UProjectileShooter::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UProjectileShooter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ticks += DeltaTime;
	// ...
}

void UProjectileShooter::FireProjectile()
{
	if (ticks >= fireRate) {
		if (projectileClass)
		{
			AActor* ownerActor = this->GetOwner();
			FVector cameraLocation;
			FRotator cameraRotation;
			ownerActor->GetActorEyesViewPoint(cameraLocation, cameraRotation);

			FVector projectileLocation = cameraLocation + FTransform(cameraRotation).TransformVector(projectileOffset);
			FRotator projectileRotation = cameraRotation;

			projectileRotation.Pitch += 10.0f;
			UWorld* world = GetWorld();
			if (world)
			{
				FActorSpawnParameters spawnParams;
				spawnParams.Owner = ownerActor;
				AProjectile* projectile = world->SpawnActor<AProjectile>(projectileClass, projectileLocation, projectileRotation, spawnParams);
				if (projectile)
				{
					FVector launchDirection = projectileRotation.Vector();
					projectile->FireInDirection(launchDirection);
					projectile->SetDamage(this->damage);
				}
			}
			ticks = 0.0f;
		}
	}
	
}

void UProjectileShooter::SetDamage(int damage_)
{
	this->damage = damage_;
}

