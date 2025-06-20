// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "Bloque_Ladrillo.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API ABloque_Ladrillo : public ABloque
{
	GENERATED_BODY()
public:
	ABloque_Ladrillo();
	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//void MoverBloque(float DeltaTime);
	float alturaMax=1000;
	bool Subiendo;
	float tiempo;
	float velocidad = 200;
	FVector PosicionActual;
	UMaterial*Material3;
};
