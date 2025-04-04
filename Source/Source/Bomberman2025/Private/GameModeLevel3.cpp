// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeLevel3.h"
#include "Enemigo.h"
#include "Bloque.h"
#include "Bloque_Acero.h"
#include "Bloque_Ladrillo.h"
#include "Bloque_Concreto.h"
#include "Bloque_Madera.h"
#include "Bloque_Cuarzo.h"
#include "Bloque_Burbuja.h"
#include "Bloque_Vidrio.h"
#include "Bloque_Hielo.h"
#include "Bloque_Oro.h"
#include "Bloque_Pasto.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
AGameModeLevel3::AGameModeLevel3()
{
    PrimaryActorTick.bCanEverTick = true;
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }

}
void AGameModeLevel3::BeginPlay()
{
    Super::BeginPlay();
    FVector SpawnLocation = FVector(0.0f, 0.0f, 100.0f);
    float Espaciado = 600.0f;
    FVector Bloque_Inicial = FVector(-14953.0, -14984.187776, 0.0f);
    if (GetWorld())
    {
        for (int fila = 0; fila < MapaBloques.Num(); fila++)//Bucle para generar 
        {
            for (int columna = 0; columna < MapaBloques[fila].Num(); columna++)
            {
                int32 valor = MapaBloques[fila][columna];
                FVector Ubicacion_de_Bloques = Bloque_Inicial + FVector(fila * Espaciado, columna * Espaciado, 0);
                Spawnearbloques(Ubicacion_de_Bloques, valor);


            }
        }

    }
    Enemigo = GetWorld()->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
}

void AGameModeLevel3::Spawnearbloques(FVector Ubicacion, int32 Bloque) {
    ABloque* TipoBloque = nullptr;
        switch (Bloque) 
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
            TipoBloque = GetWorld()->SpawnActor<ABloque_Cuarzo>(ABloque_Cuarzo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
            break;
        }
        case 6:
        {
            TipoBloque = GetWorld()->SpawnActor<ABloque_Oro>(ABloque_Oro::StaticClass(), Ubicacion, FRotator::ZeroRotator);
            break;
        }
        case 7:
        {
            TipoBloque = GetWorld()->SpawnActor<ABloque_Burbuja>(ABloque_Burbuja::StaticClass(), Ubicacion, FRotator::ZeroRotator);
            break;
        }
        case 8:
        {
            TipoBloque = GetWorld()->SpawnActor<ABloque_Hielo>(ABloque_Hielo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
            break;
        }
        case 9:
        {
            TipoBloque = GetWorld()->SpawnActor<ABloque_Vidrio>(ABloque_Vidrio::StaticClass(), Ubicacion, FRotator::ZeroRotator);
            break;
        }
        case 10:
        {
            TipoBloque = GetWorld()->SpawnActor<ABloque_Pasto>(ABloque_Pasto::StaticClass(), Ubicacion, FRotator::ZeroRotator);
            break;
        }
        default:
            break;
        }
        if (TipoBloque) {
            TipoBloque->SetActorScale3D(FVector(6.0f, 6.0f, 5.0f));

    }


}
 



