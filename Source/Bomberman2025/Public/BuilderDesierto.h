// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderEscenario.h"
#include "ElementosDesierto.h"
#include "BuilderDesierto.generated.h"
class APuertaNiveles;
UCLASS()
class BOMBERMAN2025_API ABuilderDesierto : public AActor, public IIBuilderEscenario
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderDesierto();

	ALaberintoTerminado* Laberinto;
	int CantidadPuertas=1; 
	int CantidadEntorno=3;
	int CantidadDecoracion=1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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
	AElementosDesierto* ElementoDesierto;

	//Posiciones 
	TArray<FTransform>PosicionDesierto1 = {
	FTransform(FRotator(0.0f, 90.0f, 0.0f),FVector(10380.0,-300.0,-2730.0), FVector(50.0, 50.0, 70.0)),
	FTransform(FRotator(0.0f, 180.0f, 0.0f),FVector(-100.0,9970.0,-2730.0), FVector(50.0, 50.0, 70.0)),
	FTransform(FRotator(0.0f, -90.0f, 0.0f),FVector(-2700.0,-10120.0,-2730.0), FVector(50.0, 50.0, 70.0))
	};
	TArray<FTransform>PosicionDesierto2 = {
	FTransform(FRotator(0.0f, 0.0f, 0.0f),FVector(7120.0,-11130.0,-440.0), FVector(10.0f, 10.0f, 10.0f)),
	FTransform(FRotator(0.0f, 0.0f, 0.0f),FVector(7120.0,10820.0,-440.0), FVector(10.0f, 10.0f, 10.0f)),
	FTransform(FRotator(0.0f, 0.0f, 0.0f),FVector(-9730.0,10820.0,-440.0), FVector(10.0f, 10.0f, 10.0f))
	};
	TArray<FTransform>PosicionDesierto3 = {
	FTransform(FRotator(0.0f, 0.0f, 0.0f),FVector(-9340.0,-5450.0,-420.0), FVector(0.05, 0.04,0.04)),
	FTransform(FRotator(0.0f, 0.0f, 0.0f),FVector(-9340.0,1650.0,-420.0), FVector(0.05, 0.04,0.04)),
	FTransform(FRotator(0.0f, 0.0f, 0.0f),FVector(-17060.0,-1100.0,-420.0f), FVector(0.05, 0.08, 0.07))
	};
};
