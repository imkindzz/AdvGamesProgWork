// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupRotatorComponent.h"

// Sets default values for this component's properties
UPickupRotatorComponent::UPickupRotatorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPickupRotatorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPickupRotatorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Rotate the object
	TickRotateObject(DeltaTime);
}


void UPickupRotatorComponent::TickRotateObject(const float& DeltaTime)
{
	// Get the current rotation of the owning actor
	FRotator CurrentActorRotation = GetOwner()->GetActorRotation();

	// Increment the Yaw (rotation around the Z axis)
	CurrentActorRotation.Yaw += DeltaTime * RotationSpeed;

	// Set the new rotation
	GetOwner()->SetActorRotation(CurrentActorRotation);
}


