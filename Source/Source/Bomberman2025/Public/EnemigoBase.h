// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemigoBase.generated.h"

UCLASS()
class BOMBERMAN2025_API AEnemigoBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemigoBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//Acciones 
	virtual void Atacar();
	virtual void Morir();
	virtual void Mover();
	void Destruir();
	float Vida = 100;

	FTimerHandle TemporizadorReinicioAtaque;
	bool bPuedeAtacar = true;
	bool bEstaCaminando = true;

	virtual float GetDistanciaAtaque() { return 200.0f; }
	virtual float GetVelocidadMovimiento() { return 0.0f; }

	FTimerHandle TemporizadorMuerte;
	void ReiniciarAtaque();
	//Animaciones
	UAnimSequence* AnimacionAtaque;
	UAnimSequence* AnimacionMorir;
	UAnimSequence* AnimacionCaminar;
	UAnimSequence* AnimacionIdle;
	
};
