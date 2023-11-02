// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOONTANKS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "health")  
	float MaxHealth = 100.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "health",  meta = (AllowPrivateAccess = "true"))  
	float Health = 0.f;
	UFUNCTION()
	void DamageTaken(
		AActor* DamageActor, // taken damage actor
		float Damage,  // what damage
		const UDamageType* DamageType, // what damage? poison, hit, etc..
		class AController* Instigator, // who are damage controll
		AActor* DamageCauser  // make damage actor
		);
	class AToonTanksGameMode* ToonTanksGameMode;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
