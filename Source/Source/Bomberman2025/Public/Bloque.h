// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.generated.h"

UCLASS()
class BOMBERMAN2025_API ABloque : public AActor
{
	GENERATED_BODY()


	// Sets default values for this actor's properties
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
public:
	ABloque();
	UStaticMeshComponent* Mesh;
	UStaticMesh* Malla;
	//ejercicio 4
	TArray<TFunction <void(float DeltaTime)>>Funciones;
	bool Encendido=true; 
	bool Activado;
	float velocidad=150;
	float AlturaMax=800;
	FVector PosicionActual;
	FVector PosicionInicial;
	void MovHorizontal(float time);
	void MovVertical(float time);
	TFunction<void(float )>Funcion;
	FString GetNombreBloque();
	// FACTORY METHOD

protected:
	FString NombreBloque;
};