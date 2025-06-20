// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaberintoTerminado.h"
#include "IBuilderEscenario.h"
#include "ElementosLava.h"
#include "BuilderLava.generated.h"
class APuertaNiveles;

UCLASS()
class BOMBERMAN2025_API ABuilderLava : public AActor, public IIBuilderEscenario
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderLava();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int CantidadPuertas = 1;
	int CantidadEntorno = 4;
	int CantidadDecoracion = 1;
	int CantidadPowerUp = 16;
	TArray<FVector>PosicionPowerUps;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void ConstruirBloqueFijo() override;
	virtual void ConstruirBloqueDestructible() override;
	virtual void ConstruirEntorno(int cantidad) override;
	virtual void ConstruirDecoracion(int cantidad) override;
	virtual void ConstruirPuerta(int cantidad) override;
	virtual ALaberintoTerminado* GetLaberinto() override;
	FVector Ubicacion_Inicial;
	ALaberintoTerminado* Laberinto;
	AElementosLava* ElementoLava;
	TSubclassOf<APuertaNiveles> ClasePuertaSiguiente;
	virtual TSubclassOf<AActor> ObtenerClasePuerta() override;

	TArray<FTransform>PosicionEntorno = {
	FTransform(FRotator(0.0f, 270.0f, 0.0f),FVector(-7229.773405f,-893.093779f,-170.0f), FVector(0.15f, 0.15f,0.15f)),
	FTransform(FRotator(0.0f,0.0f,0.0f),FVector(610.226595,-7273.093779,-265.361316), FVector(0.15f, 0.15f,0.15f)),
	FTransform(FRotator(0.0f, 90.0f, 0.0f),FVector(7220.226595f,546.906221,-170.0), FVector(0.15f, 0.15f,0.15f)),
	FTransform(FRotator(0.0f,180.0f,0.0f),FVector(-1689.773405,7276.906221,-170.0), FVector(0.15f, 0.15f,0.15f))
	};

	virtual int GetCantidadPuertas()  override { return CantidadPuertas; }
	virtual int GetCantidadEntorno()  override { return CantidadEntorno; }
	virtual int GetCantidadDecoracion()  override { return CantidadDecoracion; }
};
