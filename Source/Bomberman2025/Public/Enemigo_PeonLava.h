// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoBase.h"
#include "Enemigo_PeonLava.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API AEnemigo_PeonLava : public AEnemigoBase
{
	GENERATED_BODY()
private:
	virtual void BeginPlay() override;
	
public: 
	AEnemigo_PeonLava();

	virtual float GetVida() override { return Vida = 100; }

	virtual float GetDanio() override;

};
