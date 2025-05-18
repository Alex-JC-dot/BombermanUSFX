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
	FVector EscalaInicial;
	FVector EscalaTope;
	float Velocidad=0.0f;
	bool VelocidadActiva=true;
	float aceleracion =0.1f;
	float velocidadtope =2.0f;
	void CrecimientoVelocidad(float time);
	bool Activado=true;
	void Crecimiento(float time);
private:
	FVector EscalaActual;
};
