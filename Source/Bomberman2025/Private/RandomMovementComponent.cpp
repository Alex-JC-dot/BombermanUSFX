// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomMovementComponent.h"

// Sets default values for this component's properties
URandomMovementComponent::URandomMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MovementRadius = 100.0f;

	// ...
}


// Called when the game starts
void URandomMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetOwner()->GetActorLocation();
	
}


// Called every frame
void URandomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AActor* Parent = GetOwner();
	if (Parent)
	{
			// Generar un desplazamiento aleatorio dentro del MovementRadius
			FVector RandomOffset(
				FMath::FRandRange(-MovementRadius, MovementRadius),
				FMath::FRandRange(-MovementRadius, MovementRadius),
				FMath::FRandRange(-MovementRadius, MovementRadius));

			FVector NewLocation = InitialLocation + RandomOffset;
			Parent->SetActorLocation(NewLocation);
	}
	// ..
	// ...
}

