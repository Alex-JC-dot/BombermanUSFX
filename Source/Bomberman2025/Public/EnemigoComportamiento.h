// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemigoComportamiento.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UEnemigoComportamiento : public UObject
{
	GENERATED_BODY()

public:
	virtual void EjecutarComportamiento(class AEnemigoBase* Enemigo) PURE_VIRTUAL(UEnemigoComportamiento::EjecutarComportamiento, );
	virtual void ForzarNuevoDestino() {}
};
