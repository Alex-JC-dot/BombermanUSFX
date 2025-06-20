// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaBloques.h"
#include "FabricaBloquesLevel2.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API AFabricaBloquesLevel2 : public AFabricaBloques
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override ;
public: 
	/*virtual ABloque* CrearBloque(FString TipoBloque) override;	
	void CrearBloquesAutomaticamente();*/
};
