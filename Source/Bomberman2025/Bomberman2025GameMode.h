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
#include"BuilderAntiguo.h"
#include "GestorEscenarios.h"
#include "Bomberman2025GameMode.generated.h"

UCLASS()
class ABomberman2025GameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ABomberman2025GameMode();

public:
    virtual void BeginPlay() override;
    
    void CambiarEscenario(ETipoEscenario NuevoEscenario);

private:
    ADirector* Director;
    ABuilderLava* BuilderLava;
    ABuilderMedieval* BuilderMedieval;
    ABuilderDesierto* BuilderDesierto;
    ABuilderCementerio* BuilderCementerio;
    ABuilderAntiguo* BuilderAntiguo;
    TArray <TSubclassOf <AEnemigo>> TipoEnemigo;

   
    //BUilder 

    ABuiilderHordaEsqueleto* BuilderEnemigos;  // Punteros para el builder especifico y el director
    ADirector_Enemigos* DirectorEnemigos;
    
    UGestorEscenarios* GestorEscenarios;
   

};