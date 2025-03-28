// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeLevel2.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API AGameModeLevel2 : public AGameModeBase
{
	GENERATED_BODY()
public:
    AGameModeLevel2();

protected:
    virtual void BeginPlay() override;

private:
    void GenerarLaberinto();

    UPROPERTY(EditDefaultsOnly, Category = "Configuración")
    TSubclassOf<class AMuro1> ClaseMuro1;

    static constexpr int filas = 20;
    static constexpr int columnas = 20;

    int MapaLaberinto[filas][columnas];
};
