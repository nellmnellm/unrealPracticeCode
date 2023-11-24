// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleWidget.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UTitleWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Difficulty = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Sensitivity = 1;
	UFUNCTION(BlueprintCallable)
	void SetOption();
};
