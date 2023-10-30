// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"


UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Base Pawn double")
	int32 VisibleAnywhereInt = 12;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FString GoodProperty = TEXT("good");

	UPROPERTY(VisibleInstanceOnly)
	float VisibleInstanceOnly = 22;
	*/
	/*etc... UPROPERTY(VisibleDefaultOnly)
	UPROPERTY(EditDefaultOnly)
	UPROPERTY(EditInstaceOnly)
	*/
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh; // actor include staticmeshcomp
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh; 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;
	
	
	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Base Pawn double", meta = (AllowPrivateAccess = "true"))
	int32 VisibleAnywhereInt2 = 32;*/
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	

};
