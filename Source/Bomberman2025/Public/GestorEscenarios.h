// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Director.h"
#include "IBuilderEscenario.h"
#include "BuilderCementerio.h"
#include "BuilderConcreto.h"
#include "BuilderDesierto.h"
#include "BuilderLava.h"
#include "BuilderHielo.h"
#include "BuilderMedieval.h"
#include "LaberintoTerminado.h"
#include "BuiilderHordaEsqueleto.h"
#include "BuilderHordaGuerrero.h"
#include "BuilderHordaUrbana.h"
#include "BuilderHordaHielo.h"
#include "GestorEnemigos.h"
#include "Director_Enemigos.h"
#include "HordaEnemigos.h"
#include "Sound/SoundWave.h"
#include "Sound/SoundBase.h"
#include "Components/AudioComponent.h"
#include "GestorEscenarios.generated.h"

class ABuilderAntiguo;
class APuertaNiveles;

UENUM(BlueprintType)
enum class ETipoEscenario : uint8
{
    Antiguo        UMETA(DisplayName = "Antiguo"),
    Cementerio     UMETA(DisplayName = "Cementerio"),
    Urbano         UMETA(DisplayName = "Urbano"),
    Lava           UMETA(DisplayName = "Lava"),
    Hielo          UMETA(DisplayName = "Hielo"),
    Desierto       UMETA(DisplayName = "Desierto"),
    Medieval       UMETA(DisplayName = "Medieval")
};

UCLASS()
class BOMBERMAN2025_API UGestorEscenarios : public UObject
{
    GENERATED_BODY()

public:
    UGestorEscenarios();
    static FName ObtenerNombreNivelDesdeEscenario(ETipoEscenario TipoEscenario);
    void ConstruirEscenario(UWorld* Mundo, ETipoEscenario Escenario);
 /*   void DestruirEscenarioActual();*/
    TScriptInterface<IIBuilderEscenario> GetBuilderInterfaceFromActor(AActor* Actor);

    UPROPERTY()
    ALaberintoTerminado* LaberintoFinal;

    UPROPERTY()
    AHordaEnemigos* Horda;

    UPROPERTY()
    AGestorEnemigos* GestorEnemigos;

private:
    void ConstruirEscenarioContinuar();
    //void LimpiarConstructores();
    //bool ValidarActores() const;

    UPROPERTY()
    UWorld* MundoGuardado;

    ETipoEscenario EscenarioGuardado;
    FTimerHandle TimerHandle_ConstruirEscenario;

    // Directores
    UPROPERTY()
    ADirector* DirectorLaberinto;

    UPROPERTY()
    ADirector_Enemigos* DirectorEnemigos;

    // Builders de Escenarios
    UPROPERTY()
    ABuilderAntiguo* BuilderAntiguo;

    UPROPERTY()
    ABuilderHielo* BuilderHielo;

    UPROPERTY()
    ABuilderConcreto* BuilderUrbano;

    UPROPERTY()
    ABuilderCementerio* BuilderCementerio;

    UPROPERTY()
    ABuilderLava* BuilderLava;

    UPROPERTY()
    ABuilderDesierto* BuilderDesierto;

    UPROPERTY()
    ABuilderMedieval* BuilderMedieval;

    // Builders de Enemigos
    UPROPERTY()
    ABuiilderHordaEsqueleto* BuilderHordaEsqueleto;

    UPROPERTY()
    ABuilderHordaGuerrero* BuilderHordaGuerrero;

    UPROPERTY()
    ABuilderHordaHielo* BuilderHordaHielo;

    IIBuilderEscenario* BuilderAbstracto;

    UPROPERTY()
    ABuilderHordaUrbana* BuilderHordaUrbana;

    UPROPERTY()
    UAudioComponent* AudioComponentMusicaNivel;

    UPROPERTY(EditAnywhere, Category = "Audio")
    USoundBase* MusicaAntigua;

    UPROPERTY(EditAnywhere, Category = "Audio")
    USoundBase* MusicaCementerio;


    UPROPERTY(EditAnywhere, Category = "Audio")
    USoundBase* MusicaUrbana;

    UPROPERTY(EditAnywhere, Category = "Audio")
    USoundBase* MusicaHielo;

    void ReproducirMusicaDeNivel(USoundBase* Musica);


};