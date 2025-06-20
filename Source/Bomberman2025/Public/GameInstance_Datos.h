// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GestorEscenarios.h"
#include "GameInstance_Datos.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UGameInstance_Datos : public UGameInstance
{
	GENERATED_BODY()
private:
    int DificultadSeleccionada;

public:
    int DanoExplosion;
    int DanoEnemigo;
    int DanoProyectil;
    int VidaActual;
    int VidaMax;
    int CantidaEnemigos;

    void EstablecerDificultadInt(int Valor) { DificultadSeleccionada = Valor; }
    int ObtenerDificultadInt()  { return DificultadSeleccionada; }

    void EstablecerDanoEnemigo(int Dano) { DanoEnemigo =Dano; }
    int ObtenerDanoEnemigo() { return DanoEnemigo; }

    void EstablecerDanoExplosion(int Dano) { DanoExplosion = Dano; }
    int ObtenerDanoExplosion() { return DanoExplosion; }

    void EstablecerDanoProyectil(int Dano) { DanoProyectil = Dano; }
    int ObtenerDanoProyectil() { return DanoProyectil; }

    void EstablecerVidaMax(int NVidaMax) { VidaMax = NVidaMax; }
    int ObtenerVidaMax() { return VidaMax; }

    void EstablecerVida(int Vida) { VidaActual = Vida; }
    int ObtenerVidaActual() { return VidaActual; }


    void EstablecerCantidadEnemigos(int Cantidad) { CantidaEnemigos = Cantidad; }
    int ObtenerCantidadEnemigos() { return CantidaEnemigos; }



    UPROPERTY(BlueprintReadWrite)
    ETipoEscenario EscenarioActual;
};
