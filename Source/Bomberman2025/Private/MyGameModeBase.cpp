// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"
#include "Bloque.h"
#include "FabricaBloqueMadera.h"
#include "UObject/ConstructorHelpers.h"
#include "MyPrototype.h"
#include "W_Dificultad.h"
#include "GestorDificultad_Facade.h"
#include "Kismet/GameplayStatics.h"
#include "Enemigo_Subterraneo.h"
#include "Engine/World.h"
AMyGameModeBase::AMyGameModeBase()
{
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}

void AMyGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    float TamanoCelda = 400.0f;
    FVector UbicacionInicial = FVector(-3994.488813, -3997.341838, -50.0f);
    FabricaMadera = GetWorld()->SpawnActor<AFabricaBloqueMadera>(AFabricaBloqueMadera::StaticClass());
    if (GetWorld())
    {
        for (int i = 0; i < Laberinto.Num(); i++)
        {
            for (int j = 0; j < Laberinto[i].Num(); j++)
            {
                int valor = Laberinto[i][j];

                FVector PosicionActual = UbicacionInicial + FVector(i * TamanoCelda, j * TamanoCelda, 50.0f);
 
                if (valor == 0&&EnemigosCreados < MaxEnemigos) {
                    FVector Posicion = PosicionActual+FVector(TamanoCelda / 2.0f, TamanoCelda / 2.0f, 0.0f);
                    FabricaMadera->CrearEnemigoMadera(Posicion);
                    EnemigosCreados++;
                }
                if (valor==1){ FabricaMadera->CrearBloqueMadera(PosicionActual);}

                if (valor == 3) { FabricaMadera->CrerarArbolMadera(PosicionActual);}

                if (valor == 5) { FabricaMadera->CrearPlanta(PosicionActual); }
                if (valor == 6) {
                    FRotator Rotacion(0.0f, 270.0f, 0.0f);
                    FabricaMadera->CrearMonumento(PosicionActual, Rotacion);
                }
                if (valor == 7) {
                    FRotator Rotacion(0.0f, 90.0f, 0.0f);
                    FabricaMadera->CrearMonumento(PosicionActual+FVector(500.0f,0.0f,0.0f), Rotacion);
                }
            }
        }
    }


    UGameInstance_Datos* GameInstance = Cast<UGameInstance_Datos>(GetGameInstance());
    if (GameInstance)
    {
        int Dificultad = GameInstance->ObtenerDificultadInt();

        AGestorDificultad_Facade* Gestor = GetWorld()->SpawnActor<AGestorDificultad_Facade>(AGestorDificultad_Facade::StaticClass());
        if (Gestor) {
            Gestor->ConfigurarNivel(Dificultad);
            GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, TEXT("Si se pudo crear el gestor"));
        }
    }
 
    //AEnemigo* Original = GetWorld()->SpawnActor<AEnemigo>(AEnemigo_Subterraneo::StaticClass(), FVector(-2635.705603, -2595.791139, 100), FRotator::ZeroRotator);
    //IMyPrototype* Prototipo = Cast<IMyPrototype>(Original);
    //if (Prototipo)
    //{
    //    for (int i = 0; i < 5; ++i) 
    //    {
    //        AEnemigo* Copia = Cast<AEnemigo>(Prototipo->Clone());
    //        if (Copia)
    //        {
    //            // Colocamos la copia en una posición distinta
    //            FVector NuevaPosicion = FVector(800 * i, 0.0f, 100); // Puedes ajustar esto
    //            Copia->SetActorLocation(NuevaPosicion);
    //        }
    //    }
    //}
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (PC)
    {
        PC->SetInputMode(FInputModeGameOnly());
        PC->bShowMouseCursor = false;
    }
 
}
