// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderEscenario.h"
#include "LaberintoTerminado.h"
#include "ElementosAntiguo.h"
#include "BuilderAntiguo.generated.h"

class APuertaNiveles;

UCLASS()
class BOMBERMAN2025_API ABuilderAntiguo : public AActor, public IIBuilderEscenario
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderAntiguo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int CantidadPuertas = 1;
	int CantidadEntorno = 2;
	int CantidadDecoracion = 1;
	int CantidadPowerUp = 16;
	TArray<FVector>PosicionPowerUps;

public:	
	
	virtual void Tick(float DeltaTime) override;


	virtual void ConstruirBloqueFijo() override;
	virtual void ConstruirBloqueDestructible() override;
	virtual void ConstruirEntorno(int cantidad) override;
	virtual void ConstruirDecoracion(int cantidad) override;
	virtual void ConstruirPuerta(int cantidad) override;
	virtual class ALaberintoTerminado* GetLaberinto() override;
	
	ALaberintoTerminado* Laberinto;
	FVector Ubicacion_Inicial;
	AElementosAntiguo* ElementoAntiguo;
	TSubclassOf<APuertaNiveles> ClasePuertaSiguiente;
	virtual TSubclassOf<AActor> ObtenerClasePuerta() override;



	virtual int GetCantidadPuertas() { return CantidadPuertas; }
	virtual int GetCantidadEntorno() { return CantidadEntorno; }
	virtual int GetCantidadDecoracion() { return CantidadDecoracion; }


	//Posicion
	TArray<FTransform>PosicionRuina = {
	FTransform(FRotator(0.0f, 90.0f, 0.0f),FVector(10140.0,-4870.0,100.0f), FVector(20.0f, 20.0f, 20.0f)),
		FTransform(FRotator(0.0f, 180.0f, 0.0f),FVector(10140.0,3770.0,100.0f), FVector(20.0f, 20.0f, 20.0f))
	};
	TArray<FTransform>PosicionMonumento = {

			FTransform(FRotator(0.0f, 180.0f, 0.0f),FVector(160.0,-17187.0,244.0f), FVector(150.0f, 150.0f, 150.0f)),
			FTransform(FRotator(0.0f, 0.0f, 0.0f),FVector(225.0,17011.0,244.0f), FVector(150.0f, 150.0f, 150.0f))

	};
};
