// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoBase.h"
#include "Enemigo_EsqueletoPeon.generated.h"

UCLASS()
class BOMBERMAN2025_API AEnemigo_EsqueletoPeon : public AEnemigoBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public:

	AEnemigo_EsqueletoPeon();
	virtual float GetVelocidadMovimiento() override { return 350.0f; }
	virtual float GetDistanciaAtaque() override { return 270.0f; }
	FTimerHandle TiempoMovimiento;
	void SeguirJugador();
};
