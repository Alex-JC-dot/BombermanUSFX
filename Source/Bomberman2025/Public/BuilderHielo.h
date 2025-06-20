// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderEscenario.h"

#include "BuilderHielo.generated.h"
class APuertaNiveles;
UCLASS()
class BOMBERMAN2025_API ABuilderHielo : public AActor, public IIBuilderEscenario
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderHielo();
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
	TArray<FTransform>PosicionMuchasMontanas = {
	FTransform(FRotator(11.5, 90.0f, 0.0f),FVector(9760.0f,18210.0f,3060.0f)),
	FTransform(FRotator(10.840956 ,180.0f,0.0f),FVector(-18400.0,3650.0f,2400.0f))
	};
	TArray<FTransform>PosicionMontanas = {
	FTransform(FRotator(-2.0f, 180.0f, 0.0f),FVector(10970.0f,-1540.0,-240.0)),
	FTransform(FRotator(0.0f,90.0f,0.0f),FVector(550.0,-10950.0,-570.0), FVector(1.0f, 2.0f,1.0f))
	};
	virtual int GetCantidadPuertas()  override { return CantidadPuertas; }
	virtual int GetCantidadEntorno()  override { return CantidadEntorno; }
	virtual int GetCantidadDecoracion()  override { return CantidadDecoracion; }


	TArray<FVector>PosicionSegura;


};
