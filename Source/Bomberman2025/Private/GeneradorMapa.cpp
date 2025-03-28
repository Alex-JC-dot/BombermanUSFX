#include "GeneradorMapa.h"
#include "Muro1.h"
#include "Engine/World.h"

// Sets default values
AGeneradorMapa::AGeneradorMapa()
{
    // Hacer que este actor llame a Tick() cada cuadro (puede desactivarse para mejorar el rendimiento)
    PrimaryActorTick.bCanEverTick = true;
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

// Called when the game starts or when spawned
void AGeneradorMapa::BeginPlay()
{
    Super::BeginPlay();

    // Verificar si ClaseMuro1 está asignada
    if (!ClaseMuro1)
    {
        UE_LOG(LogTemp, Error, TEXT("ClaseMuro1 no ha sido asignada en GeneradorMapa."));
        return;
    }

    // Llamar a la generación del laberinto
    GenerarLaberinto();
}

void AGeneradorMapa::GenerarLaberinto()
{
    if (!GetWorld())
    {
        UE_LOG(LogTemp, Error, TEXT("No se pudo obtener el mundo en GeneradorMapa."));
        return;
    }

    float TamanoCelda = 300.0f; // Distancia entre cada muro

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (MapaLaberinto[i][j] == 1) // Si es un muro
            {
                FVector Posicion(i * TamanoCelda, j * TamanoCelda, 50.0f);
                FRotator Rotacion = FRotator::ZeroRotator;

                GetWorld()->SpawnActor<AMuro1>(ClaseMuro1, Posicion, Rotacion); // Spawnear el Muro en la posición
            }
        }
    }
}

