// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

private:

	
	

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseScreenClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinScreenClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LineOfSightClass;
	UPROPERTY(EditAnywhere)
	float RestartDelay = 5;

	FTimerHandle RestartTimer;
	UPROPERTY(EditAnywhere)
	UUserWidget* LineOfSight;

public:
	UFUNCTION(BlueprintCallable)
    void OpenMenu();
    UFUNCTION(BlueprintCallable)
    void CloseMenu();
    UPROPERTY(BlueprintReadWrite)
	bool bIsMenuOpen;
    UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> MenuClass;
    UPROPERTY(EditAnywhere)
    UUserWidget* Menu;
};
