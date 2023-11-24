// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"
#include "optionInstance.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();
    //APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    //SetFocus(PlayerPawn);
    
    
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        
        
    GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
        


}

void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    /*APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
   
    if (LineOfSightTo(PlayerPawn))
    {
        SetFocus(PlayerPawn);
        MoveToActor(PlayerPawn,AcceptanceRadius);
    }
    else
    {
        ClearFocus(EAIFocusPriority::Gameplay);
        StopMovement();
    }*/ //behavior tree use yejung
   
    /*APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    

    if (LineOfSightTo(PlayerPawn))
    {
        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
    }
    else
    {
        GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
    } */
 }


bool AShooterAIController::IsDead() const
{
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if (ControlledCharacter != nullptr)
        return ControlledCharacter->IsDead();
    return true;
}


void AShooterAIController::SetDifficulty()
{
    UoptionInstance* GameInstance = Cast<UoptionInstance>(GetGameInstance());
    if (GameInstance)
	{
        AIDifficulty = GameInstance->Diff;
        UE_LOG(LogTemp, Display, TEXT("AIDifficulty : %d"), AIDifficulty);
    }	
	else
	{
        AIDifficulty = 1;
        UE_LOG(LogTemp, Display, TEXT("AIDifficulty set false : %d"), AIDifficulty);
    }	
}
