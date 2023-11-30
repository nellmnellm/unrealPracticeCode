// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "ShooterPlayerController.h"

void UMenuWidget::WidgetReset()
{
    

    AShooterPlayerController* MenuController = GetOwningPlayer<AShooterPlayerController>();
	
    if (MenuController)
    {
        MenuController->Menu = nullptr;
        MenuController->bIsMenuOpen = false;
    }
}
