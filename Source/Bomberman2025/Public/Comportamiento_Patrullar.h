// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoComportamiento.h"
#include "Comportamiento_Patrullar.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UComportamiento_Patrullar : public UEnemigoComportamiento
{
	GENERATED_BODY()
public:
	virtual void EjecutarComportamiento(class AEnemigoBase* Enemigo) override;
	void GenerarDestinoValido(class AEnemigoBase* Enemigo) ;
	 void VerificarSiEstaAtascado(class AEnemigoBase* Enemigo) ;
	 virtual void ForzarNuevoDestino() override;
private:
	FVector DestinoActual;
	FVector UltimaPosicion;
	float TiempoSinMoverse = 0.f;
	bool bTieneDestino = false;

};
