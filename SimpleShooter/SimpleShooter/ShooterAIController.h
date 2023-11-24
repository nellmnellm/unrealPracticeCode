// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaSeconds) override;
	bool IsDead() const;
	
	UFUNCTION(BlueprintCallable)
	void SetDifficulty();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AIDifficulty;
	
protected:
	virtual void BeginPlay() override;

private:
	/* UPROPERTY(EditAnywhere)
	float AcceptanceRadius = 500; */
	
	//UPROPERTY(EditAnywhere)
	//class UBehaviorTree* AIBehavior;
	
	
};


