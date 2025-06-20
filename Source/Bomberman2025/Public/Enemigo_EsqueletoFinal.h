// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemigo_EsqueletoFinal.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API AEnemigo_EsqueletoFinal : public ACharacter
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:

	virtual void Tick(float DeltaTime) override;

	AEnemigo_EsqueletoFinal();

	void PerseguirJugador(const FVector& Destino);

	void AtacarJugador();

	void TerminarAtaque();

	void RecibirDano(float Cantidad);

	void ReproducirAnimacionInicial();


	FTimerHandle TemporizadorAtaque;

	UPROPERTY(EditAnywhere)
	float DanioAtaque;

	float Vida ;

	float VidaMaxima;

	float RangoDeteccion = 10000;

	float RangoAtaque = 400;

	float RangoAtaqueLargo = 1200.0f;

	bool bEstaAtacando;
	bool bEstaCaminando;
	bool bEstaMuerto;

	UAnimSequence* AnimacionCaminar;
	UAnimSequence* AnimacionAtaque;
	UAnimSequence* AnimacionMorir;
	
};

