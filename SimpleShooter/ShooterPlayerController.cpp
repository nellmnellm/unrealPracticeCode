// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "optionInstance.h"


void AShooterPlayerController::BeginPlay()
{
    Super::BeginPlay();
    bIsMenuOpen = false;
    
    Menu = CreateWidget<UUserWidget>(this, MenuClass);
    LineOfSight = CreateWidget(this, LineOfSightClass);
    if (LineOfSight != nullptr)
        LineOfSight->AddToViewport();
}

void AShooterPlayerController::OpenMenu()
{
    // 이미 열려있으면 중복 생성 방지
    if (!bIsMenuOpen)
    {
        
        if (MenuClass)
        {
            
            if (Menu)
            {
                
                if (Menu->IsInViewport())
                {
                    Menu->RemoveFromParent();
                }
                Menu->AddToViewport();
                bIsMenuOpen = true;
            }
        }
    }
}

void AShooterPlayerController::CloseMenu()
{
    // 이미 닫혀있으면 무시
    if (bIsMenuOpen)
    {
        if (MenuClass)
        {
            if (Menu)
            {
                Menu->RemoveFromParent();
                bIsMenuOpen = false;
            }
        }
    }
}

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    LineOfSight->RemoveFromViewport();
    
    
	
   
    if (bIsWinner)
    {
        UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
        if (WinScreen != nullptr)
        {
            WinScreen->AddToViewport();
        }
    }

    else
    {
        UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
        if (LoseScreen != nullptr)
        {
            LoseScreen->AddToViewport();
        }
       
       
        Menu = nullptr;
        bIsMenuOpen = false;
    

        
        GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
    }
   
    
}

