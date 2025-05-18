// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ILaberinto.h"
#include "Bloque.h"
#include "LaberintoTerminado.generated.h"

UCLASS()
class BOMBERMAN2025_API ALaberintoTerminado : public AActor, public	IILaberinto
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaberintoTerminado();

private:
	FString Bloque;
	FString Grada;
	FString Refugio;
	FString Puerta;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetBloque(FString _Bloque) override;
	virtual void SetGrada(FString _Grada) override;
	virtual void SetRefugio(FString _Refugio) override;
	virtual void SetPuerta(FString _Puerta) override;

//Matriz 
    TArray<TArray<int32>> MapaLaberinto =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,3,1,0,4,0,1,3,2,0,4,0,0,0,0,0,1,0,0,1},
        {1,0,1,0,2,0,1,0,1,1,5,0,1,2,1,0,1,0,0,1},
        {1,0,0,0,2,0,0,4,0,0,1,0,0,0,1,0,4,0,0,1},
        {1,2,2,0,1,1,1,1,2,0,2,1,1,0,1,1,2,1,0,1},
        {1,0,0,0,0,4,0,0,2,0,0,0,1,0,0,0,4,0,0,1},
        {1,0,2,2,1,1,1,0,1,1,1,0,2,1,1,1,1,2,0,1},
        {1,5,1,4,0,0,1,0,0,0,1,0,0,0,1,3,0,1,0,1},
        {1,1,2,0,2,1,1,1,2,0,1,1,1,0,1,1,0,1,4,1},
        {1,1,3,0,2,0,0,0,4,0,0,0,1,0,0,0,0,0,0,1},
        {1,2,1,4,1,1,1,4,1,1,1,0,2,1,1,0,1,1,2,1},
        {1,1,0,0,0,0,1,0,0,0,1,0,0,0,2,4,0,0,0,1},
        {1,3,1,2,1,0,2,1,1,0,1,1,1,0,1,1,1,1,0,1},
        {1,0,1,0,0,4,0,0,1,4,0,0,1,0,0,4,0,0,0,1},
        {1,0,1,0,2,1,1,0,2,1,1,0,2,2,1,1,1,1,0,1},
        {1,0,0,0,1,0,0,4,0,0,1,0,4,0,0,0,0,1,0,1},
        {1,1,1,0,1,0,2,1,1,0,1,2,2,1,1,1,0,1,0,1},
        {1,0,4,0,0,0,1,3,0,0,0,0,0,4,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,0,2,1,2,1,2,1,5,2,1,2,5,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
};
