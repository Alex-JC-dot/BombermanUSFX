// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IConfiguracionNivel.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UIConfiguracionNivel : public UInterface
{
	GENERATED_BODY()
};




class BOMBERMAN2025_API IIConfiguracionNivel
{
	GENERATED_BODY()


public:

	virtual void ConfigurarVida()=0;
	virtual void ConfigurarDanoBomberman() = 0;
	virtual void ConfigurarCantidadEnemigos() = 0;

};
