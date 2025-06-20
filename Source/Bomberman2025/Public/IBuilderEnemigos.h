// Esta sera la clase bastracta 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HordaEnemigos.h"
#include "IBuilderEnemigos.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIBuilderEnemigos : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN2025_API IIBuilderEnemigos
{
	GENERATED_BODY()


public:
	//Primero haremos los metodos abstractos para sobrescribirlos en el o los builders
	// le daremos un parametro cantidad para controlar el numero de instancias

	virtual void ContruirJefe(int cantidad)=0;
	virtual void ContruirEnemigoPeon(int cantidad) = 0;
	virtual void ConstruirEnemigoMagico(int cantidad) = 0;
	virtual AHordaEnemigos* GetHorda()=0;

};
