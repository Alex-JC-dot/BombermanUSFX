// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeLevel2.h"
#include "BloqueAcero3.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
AGameModeLevel2::AGameModeLevel2()
{
    PrimaryActorTick.bCanEverTick = true;
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
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
        UE_LOG(LogTemp, Error, TEXT("ClaseBloqueMuro no asignada en GameMode_Nivel2"));
        return;
    }

    float Espaciado = 400.0f;
    FVector UbicacionInicial = FVector(-3994.488813, -3997.341838, -50.0f);

    constexpr int MatrizMapa[filas][columnas] =
    {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1},
    {1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,1,0,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
    {1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1},
    {1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
    {1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    if (GetWorld())
    {
        for (int fila = 0; fila < filas; fila++)
        {
            for (int columna = 0; columna < columnas; columna++)
            {
                if (MatrizMapa[fila][columna]== 1) {
                    FVector Posicion_Actual = UbicacionInicial + FVector(fila * Espaciado, columna * Espaciado, -50.0f);
                    ABloqueAcero3* bloque1 = GetWorld()->SpawnActor<ABloqueAcero3>(ClaseMuro1, Posicion_Actual, FRotator::ZeroRotator);
                    if (bloque1) {
                        bloque1->SetActorScale3D(FVector(4.0f, 4.0f, 5.0f));
                        Matriz_de_Bloques.Add(bloque1); //guardar en el array

                    }
                }
            }
            
        }

        if (Matriz_de_Bloques.IsValidIndex(18)) {
            Matriz_de_Bloques[18]->Destroy();
        }

    }

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Laberinto 20x20 generado correctamente"));
    }
}
void AGameModeLevel2::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (!PC) return;
    FVector PuntoBase = FVector(-3994.488813, -3997.341838, -50.0f);
    static constexpr float espaciado = 400.0f;
    if (PC->WasInputKeyJustPressed(EKeys::W))
        DestruirBloqueEn(PuntoBase + FVector(espaciado, 0.0f, 0.f));

    if (PC->WasInputKeyJustPressed(EKeys::S))
        DestruirBloqueEn(PuntoBase + FVector(-espaciado, 0.0f, 0.f));

    if (PC->WasInputKeyJustPressed(EKeys::A))
        DestruirBloqueEn(PuntoBase + FVector(0.0f, -espaciado, 0.f));

    if (PC->WasInputKeyJustPressed(EKeys::D))
        DestruirBloqueEn(PuntoBase + FVector(0.0f, espaciado, 0.f));

}
void AGameModeLevel2::DestruirBloqueEn(FVector Posicion)
{
    for (ABloqueAcero3* bloque1 : Matriz_de_Bloques)
    {
        if (bloque1 && bloque1->GetActorLocation().Equals(Posicion, 20.0f))
        {
            bloque1->Destroy();
            UE_LOG(LogTemp, Warning, TEXT("Bloque destruido en %s"), *Posicion.ToString());
            break;
        }
    }
}
