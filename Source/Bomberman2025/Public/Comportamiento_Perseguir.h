// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoComportamiento.h"
#include "Comportamiento_Perseguir.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UComportamiento_Perseguir : public UEnemigoComportamiento
{
	GENERATED_BODY()

public:
	virtual void EjecutarComportamiento(class AEnemigoBase* Enemigo) override;


};
