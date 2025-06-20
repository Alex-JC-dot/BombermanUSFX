// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomba.generated.h"


UCLASS()
class BOMBERMAN2025_API ABomba : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomba();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	USkeletalMeshComponent* Mesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:

	void SpawnExplosion();
	void SpawnExplosionEn(FVector Pos);
	void Crecimiento(float time);
	void CrecimientoVelocidad(float time);
public:

	UPROPERTY(EditAnywhere, Category = "sonido")
	USoundBase* Sonido;
	// Direcciones
	int CantidadExplosion = 2;
	
	TArray<FVector> Direcciones = {
		FVector(150, 0, 0),   
		FVector(-150, 0, 0),  
		FVector(0, 150, 0),   
		FVector(0, -150, 0)   
	};

private:

	FVector EscalaInicial;
	FVector EscalaTope;
	float Velocidad=0.0f;
	bool VelocidadActiva=true;
	float aceleracion =1.0f;
	float velocidadtope =3.0f;
	bool Activado=true;	
	FVector EscalaActual;
//public:
//	virtual bool HayBombasCerca(const FVector& Posicion, float RadioDeteccion) const override; // Luis
//	
};
