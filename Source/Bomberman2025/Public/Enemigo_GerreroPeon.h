// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoBase.h"
#include "Enemigo_GerreroPeon.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API AEnemigo_GerreroPeon : public AEnemigoBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public:
	AEnemigo_GerreroPeon();


	virtual float GetVida() override { return Vida = 100; }

	virtual float GetDanio() override;
};
