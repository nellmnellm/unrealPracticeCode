// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "optionInstance.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UoptionInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
    int32 Diff;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
    float Sens;

	
};

