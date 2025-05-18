// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Bloque.h"
#include "Enemigo.h"
#include "ArbolJungla.h"
#include "Planta.h"
#include "Monumento.h"
#include "AbstractFabrica.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAbstractFabrica : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN2025_API IAbstractFabrica
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual ABloque* CrearBloqueMadera(FVector Posicion) = 0;
	virtual  AEnemigo* CrearEnemigoMadera(FVector Posicion) = 0;	
	virtual AArbolJungla* CrerarArbolMadera(FVector Posicion) = 0;
	virtual AMonumento* CrearMonumento(FVector Posicion,FRotator Rotacion ) = 0;
	virtual APlanta* CrearPlanta(FVector Posicion) = 0;
};
