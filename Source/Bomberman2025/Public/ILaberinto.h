#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ILaberinto.generated.h"

// Esta clase no necesita modificarse
UINTERFACE(MinimalAPI)
class UILaberinto : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interfaz para establecer elementos de un laberinto.
 */
class BOMBERMAN2025_API IILaberinto
{
	GENERATED_BODY()

public:
	virtual void SetBloqueFijo(FString _Bloque) = 0;
	virtual void SetBloqueDestructible(FString _Bloque) = 0;
	virtual void SetEntorno(FString _Bloque) = 0;
	virtual void SetDecoracion(FString _Bloque) = 0;
	virtual void SetPuerta(FString _Bloque) = 0;
	
};
