// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderEscenario.h"
#include "LaberintoTerminado.h"
#include "ElementosCementerio.h"
#include "BuilderCementerio.generated.h"
class APuertaNiveles;

UCLASS()
class BOMBERMAN2025_API ABuilderCementerio : public AActor, public IIBuilderEscenario
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderCementerio();

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
	virtual class ALaberintoTerminado* GetLaberinto() override;
	TSubclassOf<APuertaNiveles> ClasePuertaSiguiente;
	virtual TSubclassOf<AActor> ObtenerClasePuerta() override;


	virtual int GetCantidadPuertas() { return CantidadPuertas; }
	virtual int GetCantidadEntorno() { return CantidadEntorno; }
	virtual int GetCantidadDecoracion() { return CantidadDecoracion; }
	
	FVector Ubicacion_Inicial;
	ALaberintoTerminado* Laberinto;
	AElementosCementerio* ElementosCementerio;

	//Posiciones 
	TArray<FTransform>PosicionLapida = {
	FTransform(FRotator(0.0f, -90.0f, 0.0f),FVector(-77030.0,15.0,0.0f), FVector(10.0, 10.0, 11.0)),
		FTransform(FRotator(0.0f, 180.0f, 0.0f),FVector(429.809533,76921.0,0.0f), FVector(10.0, 10.0, 11.0)),
			FTransform(FRotator(0.0f, 90.0f, 0.0f),FVector(77409.809533,-575.0,0.0f), FVector(10.0, 10.0, 11.0)),
				FTransform(FRotator(0.0f, 0.0f, 0.0f),FVector(-360.190467,-76910.0,0.0f), FVector(10.0, 10.0, 11.0))
	};
	TArray<FTransform>PosicionIglesia = {
	FTransform(FRotator(0.0f, -38.672021 , 0.0f),FVector(-9750.0,9000.0,-600.0f), FVector(10.0f, 10.0f, 11.0f)),
	FTransform(FRotator(0.0f, 220.0 , 0.0f),FVector(10140.0,9470.0,-600.0f), FVector(10.0f, 10.0f, 11.0f)),
	FTransform(FRotator(0.0f, 140.0f, 0.0f),FVector(10140.0,-9920.0,-600.0f), FVector(10.0f, 10.0f, 11.0f)),
	FTransform(FRotator(0.0f, 35.459053, 0.0f),FVector(-10880.0,-9440.0,-600.0f), FVector(10.0f, 10.0f, 11.0f))
	};
};
