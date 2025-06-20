// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderEscenario.h"
#include "ElementosMedieval.h"
#include "LaberintoTerminado.h"
#include "BuilderMedieval.generated.h"
class APuertaNiveles;

UCLASS()
class BOMBERMAN2025_API ABuilderMedieval : public AActor, public IIBuilderEscenario
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderMedieval();
	ALaberintoTerminado* Laberinto;	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int CantidadPuertas = 1;
	int CantidadEntorno = 2;
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
	TSubclassOf<APuertaNiveles> ClasePuertaSiguiente;
	virtual TSubclassOf<AActor> ObtenerClasePuerta() override;


	FVector Ubicacion_Inicial;
	AElementosMedieval* ElementoMedieval;

	virtual int GetCantidadPuertas()  override { return CantidadPuertas; }
	virtual int GetCantidadEntorno()  override { return CantidadEntorno; }
	virtual int GetCantidadDecoracion()  override { return CantidadDecoracion; }

	//Posiciones 
	TArray<FTransform>PosicionCasa = {
	FTransform(FRotator(0.0f, 90.0f, 0.0f),FVector(5940.0f,-6030.0f,-240.0f)),
	FTransform(FRotator(0.0f ,180.0f,0.0f),FVector(-6350.0,-5740.0,-240.0))
	};
	TArray<FTransform>PosicionCaverna = {
	FTransform(FRotator(0.0f, 180.0, 0.0f),FVector(7207.0,-1536.503141,67.692151), FVector(0.13, 0.15, 0.15)),
	FTransform(FRotator(0.0f ,0.0f,0.0f),FVector(1497.0,-7436.503141,67.692151),FVector(0.13, 0.15, 0.15)),
	FTransform(FRotator(0.0f ,0.0f,0.0f),FVector(-2703.0, -7436.503141,67.692151),FVector(0.13, 0.15, 0.15)),
	FTransform(FRotator(0.0f ,270.0f,0.0f),FVector(-6788.521619,-1226.503141,67.692151),FVector(0.13, 0.15, 0.15))
	};
	TArray<FTransform>PosicionLago = {
	FTransform(FRotator(0.0f, 180.0f, 0.0f),FVector(-5920.0,2500.0,-130.0), FVector(3.0f, 3.0f, 4.0f)),
	FTransform(FRotator(0.0f, 0.0f, 0.0f),FVector(5900.0,2890.0,-140.0), FVector(3.0f, 3.0f, 4.0f)),
	
	};
	FTransform PosicionCastillo = FTransform(FRotator(0.0f, 200.0f, 0.0f), FVector(260.0, 10980.0, -290.0), FVector(0.4, 0.3575, 0.6925));
};
