// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.generated.h"

UCLASS()
class BOMBERMAN2025_API ABloque : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABloque();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY()
	UStaticMeshComponent* Mesh;
public:
	void MoverBloque(float DeltaTime);
	float alturaMax;
	UPROPERTY(EditAnywhere)
	bool activado;
	bool Subiendo;
	float tiempo;
	float velocidad=200;
	FVector PosicionActual;
	FVector PosicionFinal;
};