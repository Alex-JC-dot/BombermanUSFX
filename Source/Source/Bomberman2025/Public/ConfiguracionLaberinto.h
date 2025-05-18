// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ILaberinto.h"
#include "IBuilderEscenario.h"
#include "ConfiguracionLaberinto.generated.h"

UCLASS()
class BOMBERMAN2025_API AConfiguracionLaberinto : public AActor, public IILaberinto
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConfiguracionLaberinto();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	IIBuilderEscenario* Builder;
	virtual void SetBloque(FString _Bloque) override;
	virtual void SetGrada(FString _Bloque) override;
	virtual void SetRefugio(FString _Bloque) override;
	virtual void SetPuerta(FString _Bloque) override;

	int CantidadGrada;
	int CantidadRefugio;
	int CantidadPuerta;
};
