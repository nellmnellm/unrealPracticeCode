// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UHUDWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	int32 RemainEnemy=0;
private:
	UFUNCTION(BlueprintPure)
	int32 GetRemainEnemy();
	
	/*UFUNCTION()
	void UpdateRemainEnemy();

	FTimerHandle TimerHandle; */
};
