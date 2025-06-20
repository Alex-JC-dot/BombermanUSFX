// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LaberintoTerminado.h"
#include "IBuilderEscenario.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIBuilderEscenario : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN2025_API IIBuilderEscenario
{
	GENERATED_BODY()
protected:

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void ConstruirBloqueFijo() = 0;
	virtual void ConstruirBloqueDestructible() = 0;
	virtual void ConstruirEntorno(int cantidad) = 0;
	virtual void ConstruirDecoracion(int cantidad)=0;
	virtual void ConstruirPuerta(int cantidad) = 0;
	virtual class ALaberintoTerminado* GetLaberinto() = 0;
		
	
	virtual int GetCantidadPuertas()  { return 1; }
	virtual int GetCantidadEntorno()  {return 1; }
	virtual int GetCantidadDecoracion() { return 1; }
	virtual int GetCantidadPowerUp() { return 1; }
	virtual TSubclassOf<AActor> ObtenerClasePuerta() =0;

	
	

};
