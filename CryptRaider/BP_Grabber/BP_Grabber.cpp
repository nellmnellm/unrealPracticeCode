// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UBP_Grabber::UBP_Grabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBP_Grabber::BeginPlay()
{
	Super::BeginPlay();

	
	
}


// Called every frame
void UBP_Grabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UPhysicsHandleComponent *PhysicsHandle = GetPhysicsHandle();
	if (PhysicsHandle == nullptr)
	{
		return;
	}	

	if (PhysicsHandle ->GetGrabbedComponent() != nullptr )
	{
		FVector TargetLocation = GetComponentLocation() + GetForwardVector() * HoldDistance;
		PhysicsHandle->SetTargetLocationAndRotation(TargetLocation, GetComponentRotation());
	}
	
	/*FRotator NowRotation = GetComponentRotation();
	FString Nowlook = NowRotation.ToCompactString();
	UE_LOG(LogTemp, Display, TEXT("now look : %s"), *Nowlook);*/

	/*UWorld* World = GetWorld();
	float time = World -> TimeSeconds;
	UE_LOG(LogTemp, Display, TEXT("time : %f"), time); */

	
	
}

void UBP_Grabber::Release()
{
	UPhysicsHandleComponent* PhysicsHandle = GetPhysicsHandle();
	if (PhysicsHandle == nullptr)
	{
		return;
	}
	if (PhysicsHandle->GetGrabbedComponent() != nullptr)
	{
		PhysicsHandle->GetGrabbedComponent()->WakeAllRigidBodies(); // because, at the some time, component are sleep mode.
		PhysicsHandle->ReleaseComponent();
	}
}


void UBP_Grabber::Grab()
{

	UPhysicsHandleComponent *PhysicsHandle = GetPhysicsHandle();
	if (PhysicsHandle == nullptr)
	{
		return;
	}	

	FHitResult HitResult;
	bool HasHit = GetGrabbableInReach(HitResult);
	
	if (HasHit)
	{
		/*
		DrawDebugSphere(GetWorld(), HitResult.Location, 10, 10, FColor::Green, false, 3);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10, 10, FColor::Red, false, 3);
		AActor* HitActor = HitResult.GetActor();
		UE_LOG(LogTemp, Display, TEXT("hit actor %s"), *HitActor->GetActorNameOrLabel());
		*/
		UPrimitiveComponent* HitComponent = HitResult.GetComponent();
		HitComponent->WakeAllRigidBodies();
		PhysicsHandle->GrabComponentAtLocationWithRotation(
			HitComponent,
			NAME_None, //if skeletal mesh, his name
			HitResult.ImpactPoint,
			//HitResult.GetComponent()->GetComponentRotation()
			GetComponentRotation()
		);
		
	} 
}

UPhysicsHandleComponent* UBP_Grabber::GetPhysicsHandle() const
{
	UPhysicsHandleComponent* Result = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (Result == nullptr)
	{
		UE_LOG(LogTemp, Warning , TEXT(" NO Physicshandle Components. "));
	}	
	return Result;
}

bool UBP_Grabber::GetGrabbableInReach(FHitResult& OutHitResult) const
{
	
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance; 

	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	DrawDebugSphere(GetWorld(), End, 10, 10, FColor::Blue, false, 3);

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
		// out maegae byeonsu
	return GetWorld()->SweepSingleByChannel(
		OutHitResult, 
		Start, 
		End, 
		FQuat::Identity, 
		ECC_GameTraceChannel2,
		Sphere
	);	
};


