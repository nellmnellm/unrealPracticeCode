// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	

	StartLocation = GetActorLocation();
	
	FString MyString = "i love you"; 
	
	UE_LOG(LogTemp, Display, TEXT("My Message : %s"), *MyString);

	

	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
	
}

void AMovingPlatform::MovePlatform(float DeltaTime){
	
	
	if (ShouldPlatformReturn())
	{
		/*float OverShoot = DistanceMoved - MoveDistance;
		FString Name = GetName();
		UE_LOG(LogTemp, Display, TEXT("BeingPlay %s are Overshoot %f"), *Name, OverShoot);*/
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}	
	else
	{
		FVector CurrentLocation = GetActorLocation();
	//current Location save;

	
	//current Location are now Location
	
	/*if (CurrentLocation.Z > 4300)
	{
		CurrentSwitch = 0;
		
	}	
	else if (CurrentLocation.Z < 3800)
	{
		CurrentSwitch = 1;
	}

	if (CurrentSwitch)
		CurrentLocation.Z += 1;
	else
		CurrentLocation.Z -= 1;
	CurrentLocation.Y += 5;
	CurrentLocation.X += 15;  */
		CurrentLocation = CurrentLocation + PlatformVelocity * DeltaTime;
		SetActorLocation(CurrentLocation);


	}

};

void AMovingPlatform::RotatePlatform(float DeltaTime){
	
	//FRotator CurrentRotation = GetActorRotation();
	//CurrentRotation = CurrentRotation + RotationVelocity * DeltaTime;
	//SetActorRotation(CurrentRotation);
	AddActorLocalRotation(RotationVelocity * DeltaTime);
};

bool AMovingPlatform::ShouldPlatformReturn() const {
	

	return GetDistanceMoved() > MoveDistance;
};

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}