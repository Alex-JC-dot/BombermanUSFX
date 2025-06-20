// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderEnemigos.h"
#include "LaberintoTerminado.h"
#include "BuilderHordaHielo.generated.h"

UCLASS()
class BOMBERMAN2025_API ABuilderHordaHielo : public AActor, public IIBuilderEnemigos
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderHordaHielo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void ContruirJefe(int cantidad) override;
	virtual void ContruirEnemigoPeon(int cantidad) override;
	virtual void ConstruirEnemigoMagico(int cantidad) override;
	virtual AHordaEnemigos* GetHorda() override;
	void MezclarPosicion();
	TArray<FVector> PosicionLibre;

	ALaberintoTerminado* Laberinto;
	AHordaEnemigos* Horda;
	FVector Ubicacion_Inicial;
};
