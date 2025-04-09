// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeLevel3.h"
#include "Enemigo.h"
#include "Enemigo_Aereo.h"
#include "Enemigo_Subterraneo.h"
#include "Enemigo_Terrestre.h"
#include "Enemigo_Acuatico.h"
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
#include "Kismet/GameplayStatics.h"
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

    float Espaciado = 600.0f;
    FVector Bloque_Inicial = FVector(-14953.0, -14984.187776, 0.0f);
    TArray<FVector> Posiciones0; // para guardar los creos
    if (GetWorld())
    {
        for (int fila = 0; fila < MapaBloques.Num(); fila++)//Bucle para generar 
        {
            for (int columna = 0; columna < MapaBloques[fila].Num(); columna++)
            {
                int32 valor = MapaBloques[fila][columna];
                FVector Ubicacion_de_Bloques = Bloque_Inicial + FVector(fila * Espaciado, columna * Espaciado, 0);
                Spawnearbloques(Ubicacion_de_Bloques, valor);
                if (valor == 0) {
                    PuntoVacio.Add(Ubicacion_de_Bloques);
                }
            }
        }
        for (int i = 0; i < 7; i++) {
            SpawnEnemigoSubterraneo();
            SpawnEnemigoTerrestre();
            SpawnEnemigoAcuatico();
            SpawnEnemigoAereo();
        }
		   GetWorld()->GetTimerManager().SetTimer(TimerMovimientoEnemigos, this, &AGameModeLevel3::MoverEnemigos, 5.0f, true);
    }
	MoverBloque();  
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
        TodosLosBloques.Add(TipoBloque);

    }
    if (!BloquesPorTipo.Contains(Bloque)) {
        BloquesPorTipo.Add(Bloque, TArray<AActor*>());
    }
    BloquesPorTipo[Bloque].Add(TipoBloque);
}
 
 void AGameModeLevel3::MoverBloque()
 {
     for (auto& Par : BloquesPorTipo)
     {
         TArray<AActor*>& Bloques = Par.Value;

         if (Bloques.Num() > 0)
         {
             Bloques.Sort([](const AActor& A, const AActor& B) {
                 return FMath::RandBool(); // Orden aleatorio
                 });

             int32 Limite = FMath::Min(5, Bloques.Num());
             int32 Activados = 0;

             for (AActor* Actor : Bloques)
             {
                 if (Activados >= Limite) break;

                 ABloque* Bloque = Cast<ABloque>(Actor);
                 if (Bloque && !Bloque->activado) 
                 {
                     Bloque->activado = true; 
                     Activados++;
                 }

             }
         }
     }
 }

void AGameModeLevel3::SpawnEnemigoSubterraneo()
{
    if (PuntoVacio.Num() > 0) {

		int32 IndiceAleatorio = FMath::RandRange(0, PuntoVacio.Num() - 1);
		FVector PosicionAleatoria = PuntoVacio[IndiceAleatorio];
		AEnemigo_Subterraneo* EnemigoSub = GetWorld()->SpawnActor<AEnemigo_Subterraneo>(AEnemigo_Subterraneo::StaticClass(), PosicionAleatoria + FVector(0.0f, 0.0f, -300.f), FRotator::ZeroRotator);
		if (EnemigoSub) {
            EnemigoSub->SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));
			Enemigos.Add(EnemigoSub);
			UE_LOG(LogTemp, Warning, TEXT("Enemigos subterraneos generados: %d"), Enemigos.Num());
		}
    }
}

void AGameModeLevel3::SpawnEnemigoAereo()
{
    if (PuntoVacio.Num() > 0)
    {
        int32 IndiceAleatorio = FMath::RandRange(0, PuntoVacio.Num() - 1);
        FVector PosicionAleatoria = PuntoVacio[IndiceAleatorio];
        AEnemigo_Aereo* EnemigoAir = GetWorld()->SpawnActor<AEnemigo_Aereo>(AEnemigo_Aereo::StaticClass(), PosicionAleatoria+FVector(0.0f,0.0f,1600.0f), FRotator::ZeroRotator);
        if (EnemigoAir) {
            EnemigoAir->SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));
            Enemigos.Add(EnemigoAir);
            UE_LOG(LogTemp, Warning, TEXT("Enemigos aereos generados: %d"), Enemigos.Num());

        }
    };
}

void AGameModeLevel3::SpawnEnemigoTerrestre()
{
    if (PuntoVacio.Num() > 0)
    {
        int32 IndiceAleatorio = FMath::RandRange(0, PuntoVacio.Num() - 1);
        FVector PosicionAleatoria = PuntoVacio[IndiceAleatorio];
        AEnemigo_Terrestre* EnemigoEarth = GetWorld()->SpawnActor<AEnemigo_Terrestre>(AEnemigo_Terrestre::StaticClass(), PosicionAleatoria + FVector(0.0f, 0.0f, -300.f), FRotator::ZeroRotator);
        if (EnemigoEarth) {
            EnemigoEarth->SetActorScale3D(FVector(5.0f, 5.0f, 5.0f));
            Enemigos.Add(EnemigoEarth);
             UE_LOG(LogTemp, Warning, TEXT("Enemigos trerrestres generados: %d"), Enemigos.Num());
        }
    };
}

void AGameModeLevel3::SpawnEnemigoAcuatico()
{
    if (PuntoVacio.Num() > 0)
    {
        int32 IndiceAleatorio = FMath::RandRange(0, PuntoVacio.Num() - 1);
        FVector PosicionAleatoria = PuntoVacio[IndiceAleatorio];
        AEnemigo_Acuatico* EnemigoWater = GetWorld()->SpawnActor<AEnemigo_Acuatico>(AEnemigo_Acuatico::StaticClass(), PosicionAleatoria + FVector(0.0f, 0.0f, -300.f), FRotator::ZeroRotator);
        if (EnemigoWater) {
            EnemigoWater->SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
            Enemigos.Add(EnemigoWater);
            UE_LOG(LogTemp, Warning, TEXT("Enemigos Acuaticos generados: %d"), Enemigos.Num());
        }
    };
}

void AGameModeLevel3::MoverEnemigos()
{

    for (AActor* Enemigo : Enemigos)
    {
        if (Enemigo)
        {
            int32 Indice = FMath::RandRange(0, PuntoVacio.Num() - 1);
            FVector NuevaPosicion = PuntoVacio[Indice];

            FVector PosicionActual = Enemigo->GetActorLocation();
            float ZOriginal = PosicionActual.Z;
            float ZDestino = NuevaPosicion.Z;
            //para enemigos aereos
            if (ZOriginal > 300) 
            {
                ZDestino = ZOriginal; 
            }

            Enemigo->SetActorLocation(FVector(NuevaPosicion.X, NuevaPosicion.Y, ZDestino));
        }
    }
}





