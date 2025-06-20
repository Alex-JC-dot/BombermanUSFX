// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomberman2025/Bomberman2025Character.h"
#include "Bomberman2025/Bomberman2025GameMode.h"
#include "PuertaNiveles.generated.h"
class AGestorEscenarios;

UCLASS()
class BOMBERMAN2025_API APuertaNiveles : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuertaNiveles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UStaticMeshComponent* Mesh;

	ETipoEscenario EscenarioDestino;

	FTimerHandle TimerHandle;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
