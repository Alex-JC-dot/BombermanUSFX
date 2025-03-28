// Fill out your copyright notice in the Description page of Project Settings.

#include "Bloque.h"
#include "MyGameModeBase.h"
AMyGameModeBase::AMyGameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Aparecio el ACTOOR"));

	FVector SpawnPosition = FVector(200.0f, 300.0f, 100.0f);
	FRotator SpawnRotation = FRotator::ZeroRotator;
	FTransform SpawnTransform(SpawnRotation, SpawnPosition);
	if (GetWorld())
	{
		if (SpawnedActor)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Bloque Spawned correctamente!"));
			GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyGameModeBase::DestroyActorFunction, 10.0f, false);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Fallo al spawnear Bloque."));
		}

		SpawnedActor = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), SpawnTransform);

	}

};
void AMyGameModeBase::DestroyActorFunction()
{
	if (SpawnedActor != nullptr)
	{
		SpawnedActor->Destroy();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
			TEXT("¡Actor eliminado correctamente!"));
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Green, TEXT(" Bob ha muerto xd"));
	}
}