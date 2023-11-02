// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Projectile.h"
#include "Particles/ParticleSystem.h"
// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent> (TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent> (TEXT("Base Mesh"));
	BaseMesh -> SetupAttachment(CapsuleComp);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent> (TEXT("Turret Mesh"));
	TurretMesh -> SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent> (TEXT("Spawn Point"));
	ProjectileSpawnPoint -> SetupAttachment(TurretMesh);
}

// Called when the game starts or when spawned

// Called every frame


	/*FVector DeltaLocation(0.f);
	DeltaLocation.X = 2.f;
	AddActorLocalOffset(DeltaLocation); */


// Called to bind functionality to input


void ABasePawn::HandleDestruction()
{
// visual and sound effect
	if (DeathParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(
			this, 
			DeathParticles,
			GetActorLocation(),
			GetActorRotation()
		);
	}

	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			this,
			DeathSound,
			GetActorLocation()
		);
	}
	if (DeathCameraShakeClass)
	{
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathCameraShakeClass);
	}
}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	//TurretMesh->SetWorldRotation(LookAtRotation);
	TurretMesh->SetWorldRotation(
		FMath::RInterpTo(
			TurretMesh->GetComponentRotation(), 
			LookAtRotation,
			UGameplayStatics::GetWorldDeltaSeconds(this),
			15.f));

}


void ABasePawn::Fire()
{
	//FVector ProjectileSpawnPointLocation = ProjectileSpawnPoint->GetComponentLocation();
	/*DrawDebugSphere(
		GetWorld(),
		ProjectileSpawnPointLocation,
		25.f,
		12,
		FColor::Red,
		false,
		3.f
		); */
	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile> ( 
		ProjectileClass, 
		ProjectileSpawnPoint->GetComponentLocation(), 
		ProjectileSpawnPoint->GetComponentRotation());
	Projectile->SetOwner(this); // (projectile assign owner)
}
