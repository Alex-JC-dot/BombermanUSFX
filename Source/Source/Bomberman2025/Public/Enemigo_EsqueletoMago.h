// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoBase.h"
#include "Enemigo_EsqueletoMago.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API AEnemigo_EsqueletoMago : public AEnemigoBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public: 
	AEnemigo_EsqueletoMago();
	FTimerHandle TiempoMovimiento;
	void SeguirJugador();
	
	virtual float GetVelocidadMovimiento() override { return 300.0f; }
	virtual float GetDistanciaAtaque() override { return 1110.f; }
};
