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
	virtual void SetBloque(FString _Bloque) = 0;
	virtual void SetGrada(FString _Bloque) = 0;
	virtual void SetRefugio(FString _Bloque) = 0;
	virtual void SetPuerta(FString _Bloque) = 0;
	
};
