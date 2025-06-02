// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BuilderLava.h"
#include "BuilderMedieval.h"
#include "BuilderDesierto.h"
#include "BuilderCementerio.h"
#include "Director.h"
#include "Enemigo.h"
#include "BuiilderHordaEsqueleto.h"
#include "Director_Enemigos.h"
#include "Bomberman2025GameMode.generated.h"

UCLASS()
class ABomberman2025GameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ABomberman2025GameMode();

public:
    virtual void BeginPlay() override;

private:
    ADirector* Director;
    ABuilderLava* BuilderLava;
    ABuilderMedieval* BuilderMedieval;
    ABuilderDesierto* BuilderDesierto;
    ABuilderCementerio* BuilderCementerio;
    TArray <TSubclassOf <AEnemigo>> TipoEnemigo;
   
    //BUilder 

    ABuiilderHordaEsqueleto* BuilderEnemigos;
    ADirector_Enemigos* DirectorEnemigos;

};