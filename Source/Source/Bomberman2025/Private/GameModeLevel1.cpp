// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModeLevel1.h"
#include "Bloque.h"
#include "FabricaBloques.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"

AGameModeLevel1::AGameModeLevel1()
{
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}

void AGameModeLevel1::BeginPlay()
{
    Super::BeginPlay();
    float TamanoCelda = 400.0f;
    FVector UbicacionInicial = FVector(-3994.488813, -3997.341838, -50.0f);
    Fabrica = GetWorld()->SpawnActor<AFabricaBloques>(AFabricaBloques::StaticClass());
    if (GetWorld())
    {
        for (int i = 0; i < Laberinto.Num(); i++)
        {
            for (int j = 0; j < Laberinto[i].Num(); j++)
            {
                int valor = Laberinto[i][j];

                FVector PosicionActual = UbicacionInicial + FVector(i * TamanoCelda, j * TamanoCelda, 50.0f);
                switch (valor)
                {
                case 1: NombreBloque = "Madera"; break;
                case 2: NombreBloque = "Acero"; break;
                case 3: NombreBloque = "Concreto"; break;
                case 4: NombreBloque = "Ladrillo"; break;
                default: NombreBloque = "";
                    break;
                }
                if (Fabrica) {
                    Fabrica->CrearBloque(NombreBloque, PosicionActual);
                }

            }
        }
    }
}
