// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeLevel2.h"
#include "Bloque.h"
#include "Bloque_Ladrillo.h"
#include "Bloque_Acero.h"
#include "Bloque_Concreto.h"
#include "Bloque_Madera.h"
#include "BombermanCharacter.h" 
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
    float Espaciado = 400.0f;
    FVector UbicacionInicial = FVector(-3994.488813, -3997.341838, -50.0f);

    if (GetWorld())
    {
        for (int fila = 0; fila < Laberinto.Num(); fila++)
        {
            for (int columna = 0; columna < Laberinto[fila].Num(); columna++)
            {
                int32 valor = Laberinto[fila][columna];
                    FVector Posicion_Actual = UbicacionInicial + FVector(fila * Espaciado, columna * Espaciado, -50.0f);
                    FVector Posicion_Bomberman = UbicacionInicial + FVector(fila * Espaciado, columna * Espaciado, 220.0f);
                    ColocarBloque(valor, Posicion_Actual);
        
                   
                    if (valor == 0) {
                        PuntoVacio.Add(Posicion_Bomberman);
                    }
           
                    /*
                    if (valor == 5) {
                    BloqueLadrillo.Add(Posicion_Actual);
                    }
                    if (valor == 5 || valor || 2 && valor || 3 && valor || 4) {
                      
                    }
                  */
            }

        }
        StartPlayer();
        StartPlayer();
        StartPlayer();
        StartPlayer();
    }
};
void AGameModeLevel2::ColocarBloque(int32 bloque, FVector Ubicacion) 
{
    ABloque* TipoBloque = nullptr;
    switch (bloque)
    {

    case 1:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Ladrillo>(ABloque_Ladrillo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 2:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Concreto>(ABloque_Concreto::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 3:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Acero>(ABloque_Acero::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 4:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Madera>(ABloque_Madera::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 5:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Ladrillo>(ABloque_Ladrillo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    default:
        break;
    }
    if (TipoBloque) {
        TipoBloque->SetActorScale3D(FVector(4.0f, 4.0f, 5.0f));
    }
}
void AGameModeLevel2::StartPlayer()
{

    if (PuntoVacio.Num() > 0) 
    {
        int32 IndiceAleatorio = FMath::RandRange(0, PuntoVacio.Num() - 1);
        FVector PosicionAleatoria = PuntoVacio[IndiceAleatorio];
        ABombermanCharacter* NuevoJugador = GetWorld()->SpawnActor<ABombermanCharacter>(ABombermanCharacter::StaticClass(), PosicionAleatoria, FRotator::ZeroRotator);
        if (NuevoJugador) {
            NuevoJugador->SetActorScale3D(FVector(0.7f, 0.7f, 0.7f));

        }
    };
}
/* 
void AGameModeLevel2::CambiarBloque(FVector Posicion)
{
    if (BloqueLadrillo.Num() > 0) {
        int32 IndiceAleatorio = FMath::RandRange(0, BloqueLadrillo.Num() - 1);
        FVector PosicionAleatoria = BloqueLadrillo[IndiceAleatorio];
        ABloque_Madera* NuevoBLoque= GetWorld()->SpawnActor<ABloque_Madera>(ABloque_Madera::StaticClass(), PosicionAleatoria, FRotator::ZeroRotator);
    }
}
*/
