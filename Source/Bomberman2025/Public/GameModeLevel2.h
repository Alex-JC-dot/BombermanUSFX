// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeLevel2.generated.h"

class ABloque;
class ABombermanCharacter;
UCLASS()
class BOMBERMAN2025_API AGameModeLevel2 : public AGameModeBase
{
	GENERATED_BODY()
public:
    AGameModeLevel2();

protected:
    virtual void BeginPlay() override;
    TArray<TArray<int32 >> Laberinto=
  {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,2,0,0,0,2,0,2,0,0,0,5,0,0,0,5,0,0,1},
    {1,0,2,2,2,0,2,0,2,2,5,0,5,5,5,0,5,5,0,1},
    {1,0,0,0,2,0,0,0,0,0,5,0,0,0,5,0,0,0,0,1},
    {1,2,2,0,2,2,2,2,2,0,5,5,5,0,5,5,5,5,0,1},
    {1,0,0,0,0,0,0,0,2,0,0,0,5,0,0,0,0,0,0,1},
    {1,0,2,2,2,2,2,0,2,2,5,0,5,5,5,5,5,5,0,1},
    {1,0,2,0,0,0,2,0,0,0,5,0,0,0,5,0,0,5,0,1},
    {1,0,2,0,2,2,2,2,2,0,5,5,5,0,5,5,0,5,0,1},
    {1,0,0,0,2,0,0,0,0,2,0,0,1,0,0,0,0,0,0,1},
    {1,3,3,0,3,3,3,0,3,3,4,0,4,4,4,0,4,4,4,1},
    {1,0,0,0,0,0,3,0,0,0,4,0,0,0,4,0,0,0,0,1},
    {1,0,3,3,3,0,3,3,3,0,4,4,4,0,4,4,4,4,0,1},
    {1,0,3,0,0,0,0,0,3,0,0,0,4,0,0,0,0,0,0,1},
    {1,0,3,0,3,3,3,0,3,4,4,0,4,4,4,4,4,4,0,1},
    {1,0,0,0,3,0,0,0,0,0,4,0,0,0,0,0,0,4,0,1},
    {1,3,3,0,3,0,3,3,3,0,4,4,4,4,4,4,0,4,0,1},
    {1,0,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,0,1},
    {1,0,3,3,3,3,3,0,3,3,4,4,4,4,0,4,4,4,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    ABloque* Bloque = nullptr;

protected:
    void ColocarBloque(int32 valor,  FVector Ubicacion);
protected:
    void StartPlayer();
    TArray<FVector> PuntoVacio; // guardar los vacios
    /*
    void CambiarBloque(FVector);
    FTimerHandle Temporizador;
    TArray<FVector> BloqueLadrillo;
    TArray<AActor*> BloqueLadrillo;
    */
};

