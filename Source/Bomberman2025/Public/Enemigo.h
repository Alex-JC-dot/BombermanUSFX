// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "MyPrototype.h"
#include "Explosion.h"
#include "Enemigo.generated.h"


UCLASS()
class BOMBERMAN2025_API AEnemigo : public ACharacter,public  IMyPrototype
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UStaticMeshComponent* StaticMesh;
	USkeletalMeshComponent* Mesh;
	UBoxComponent* Colisiones;
	
	AActor* GetPlayerActor();
	virtual IMyPrototype* Clone() override;
	void SetPosicion(FVector NuevaPosicion);
;
	//Para la destruccion de Bloques

	int ExplosionesRecibidas = 0;
	int ExplosionesNecesarias = 0;
	void AplicarFeedbackVisual();
	void Destruir();
	//virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:

	float RadioDeteccion = 1000.0f; // Rango de detección
	FVector MovimientoActual;
	float DistanciaRecorrida;
	float DistanciaMaxima = 500.0f;
	virtual void SeguirJugador();
	// Función para cambiar la dirección del movimiento
	virtual void CambiarDireccion();

	// Función para mover al enemigo
	bool DetectarObstaculo(FVector Destino);

	//Funciones para la destruccion

};
