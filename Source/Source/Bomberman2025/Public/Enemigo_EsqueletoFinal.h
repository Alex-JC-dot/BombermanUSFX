// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoBase.h"
#include "Enemigo_EsqueletoFinal.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API AEnemigo_EsqueletoFinal : public AEnemigoBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	AEnemigo_EsqueletoFinal();
	FTimerHandle TiempoMovimiento;
	void SeguirJugador();

	virtual float GetVelocidadMovimiento() override { return 200.0f; }
	virtual float GetDistanciaAtaque() override { return 500.0f; }
};

