// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDWidget.h"
#include "EngineUtils.h"
#include "ShooterAIController.h"
#include "TimerManager.h"


int32 UHUDWidget::GetRemainEnemy()
{
    RemainEnemy=0;
    for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
    {
        RemainEnemy++;
    }
    return RemainEnemy;
}
/*
void UHUDWidget::UpdateRemainEnemy()
{
    GetWorld()->GetTimerManager().SetTimer(
        TimerHandle,                // 타이머 핸들
        this,                       // 호출할 객체
        &UHUDWidget::GetRemainEnemy,   // 호출할 함수
        1.0f,                        // 주기 (1초)
        true,                        // 반복 여부 (true로 설정하면 계속 반복)
        0.0f                         // 초기 지연 시간
    );
}*/





