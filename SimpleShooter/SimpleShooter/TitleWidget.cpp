// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleWidget.h"
#include "optionInstance.h"


void UTitleWidget::SetOption()
{
    UoptionInstance* GameInstance = Cast<UoptionInstance>(GetGameInstance());
	if (GameInstance != nullptr)
	{
		GameInstance -> Sens = Sensitivity;
		UE_LOG(LogTemp, Warning, TEXT("RotationRate set to: %f"), Sensitivity);
        GameInstance -> Diff = Difficulty;
        UE_LOG(LogTemp, Warning, TEXT("Difficulty set to: %d"), Difficulty);
	}
}
