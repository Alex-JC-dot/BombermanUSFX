// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeLevel2.h"
#include "BloqueAcero3.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
AGameModeLevel2::AGameModeLevel2()
{
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
    constexpr int TempMapa[filas][columnas] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Copiar `TempMapa` a `MapaLaberinto`
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            MapaLaberinto[i][j] = TempMapa[i][j];
        }
    }
}

void AGameModeLevel2::BeginPlay()
{
    Super::BeginPlay();

    if (!ClaseMuro1)
    {
        ClaseMuro1 = ABloqueAcero3::StaticClass();
    }

    GenerarLaberinto();
}

void AGameModeLevel2::GenerarLaberinto()
{
    if (!ClaseMuro1)
    {
        UE_LOG(LogTemp, Error, TEXT("ClaseBloqueMuro no asignada en GameMode_Nivel1"));
        return;
    }

    float TamanoCelda = 400.0f;
    FVector UbicacionInicial = FVector(-3994.488813, -3997.341838, -50.0f);

    if (GetWorld())
    {
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                if (MapaLaberinto[i][j] == 1)
                {
                    FVector PosicionActual = UbicacionInicial + FVector(i * TamanoCelda, j * TamanoCelda, 50.0f);
                    ABloqueAcero3* NuevoMuro1 = GetWorld()->SpawnActor<ABloqueAcero3>(ClaseMuro1, PosicionActual, FRotator::ZeroRotator);

                    if (NuevoMuro1)
                    {
                        NuevoMuro1->SetActorScale3D(FVector(4.0f, 5.0f, 4.0f));
                    }
                }
            }
        }
    }

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Laberinto 20x20 generado correctamente"));
    }
}

