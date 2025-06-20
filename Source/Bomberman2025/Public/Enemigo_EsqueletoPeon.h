// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemigo_EsqueletoPeon.generated.h"

UCLASS()
class BOMBERMAN2025_API AEnemigo_EsqueletoPeon : public ACharacter
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public:
	AEnemigo_EsqueletoPeon();


	virtual void Tick(float DeltaTime);

	void PerseguirJugador(const FVector& Destino);

	void AtacarJugador();

	void TerminarAtaque();

	void RecibirDano(float Cantidad);

	void ReproducirAnimacionInicial();


	FTimerHandle TemporizadorAtaque;
	
	UPROPERTY(EditAnywhere)
	float DanioAtaque;

	float Vida=100;

	float VidaMaxima;

	float RangoDeteccion=10000;

	float RangoAtaque = 100;

	bool bEstaAtacando;
	bool bEstaCaminando;
	bool bEstaMuerto;

	UAnimSequence* AnimacionCaminar;
	UAnimSequence* AnimacionAtaque;
	UAnimSequence* AnimacionMorir;
};
