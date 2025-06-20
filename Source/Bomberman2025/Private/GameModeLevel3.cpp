// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeLevel3.h"
#include "Enemigo.h"
#include "Enemigo_Subterraneo.h"
#include "Bloque.h"
#include "Bloque_Acero.h"
#include "Bloque_Ladrillo.h"
#include "GestorEscenarios.h"
#include "Bloque_Concreto.h"
#include "Bloque_Madera.h"
#include "Bloque_Cuarzo.h"
#include "Bloque_Hielo.h"
#include "Bloque_Pasto.h"
#include "HUD_Bomberman.h"
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
	};
    BloquesTipo.Add(ABloque_Ladrillo::StaticClass());
    BloquesTipo.Add(ABloque_Acero::StaticClass());
    BloquesTipo.Add(ABloque_Madera::StaticClass());
    BloquesTipo.Add(ABloque_Concreto::StaticClass());

    HUDClass = AHUD_Bomberman::StaticClass();
}
void AGameModeLevel3::BeginPlay()
{
    Super::BeginPlay();
    GestorEscenarios = NewObject<UGestorEscenarios>(this);
  
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
        ABloque_Acero* Bloque = Cast<ABloque_Acero>(TipoBloque);
        ListaBloqueAcero.Add(Bloque);
        break;
    }
    case 4:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Madera>(ABloque_Madera::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        ABloque_Madera* Bloque = Cast<ABloque_Madera>(TipoBloque);
        BloqueMadera.Add(Bloque);

        break;
    }
    case 5:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Cuarzo>(ABloque_Cuarzo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }

    case 8:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Hielo>(ABloque_Hielo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
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



//Ejercicio 2
void AGameModeLevel3::EliminarBLoque()
{
    if (IndiceLadrillo < BloqueMadera.Num()) {
        ABloque_Madera* Bloque = BloqueMadera[IndiceLadrillo];
        Bloque->Destroy();
        IndiceLadrillo++;
        GetWorld()->GetTimerManager().SetTimer(TiempoBloques, this, &AGameModeLevel3::EliminarBLoque, 5.0f, false);
    }

}

void AGameModeLevel3::SpawnearBloqueRandom(FVector pos, int32 valor)
{
    if (valor == 1 || valor == 10)
    {
        int i = FMath::RandRange(0, BloquesTipo.Num() - 1);

        ABloque* Bloque = GetWorld()->SpawnActor<ABloque>(BloquesTipo[i], pos, FRotator::ZeroRotator);

            if (Bloque) 
            {
                Bloque->SetActorScale3D(FVector(6.0f, 6.0f, 5.0f));
                ABloque_Madera* Bloque2 = Cast<ABloque_Madera>(Bloque);
                ABloque_Acero* Bloque3 = Cast<ABloque_Acero>(Bloque);
                if (Bloque2) {
                    BloqueMadera.Add(Bloque2);
                }
                if (Bloque3) {
                    ListaBloqueAcero.Add(Bloque3);
                }
            }
        
    }
}

void AGameModeLevel3::BloqueAcero() {
    for (ABloque_Acero* Bloque : ListaBloqueAcero) {
        if (Bloque && Bloque->MeshTemporal) {
            Bloque->Mesh->SetStaticMesh(Bloque->MeshTemporal);
        }
        FTimerDelegate Delegado;
        Delegado.BindUFunction(this, FName("cambiazo"), Bloque);
        FTimerHandle Handle;
        GetWorld()->GetTimerManager().SetTimer(Handle, Delegado, 5.0f, false);
        //GetWorld()->GetTimerManager().SetTimer(TiempoBloques, this, &AGameModeLevel3::EliminarBloqueAcero, 5.0f, false);
    }
}
void AGameModeLevel3::cambiazo(ABloque_Acero* Bloque) {
    Bloque->Mesh->SetStaticMesh(Bloque->Malla);
}
void AGameModeLevel3::EliminarBloqueAcero() {
    for (ABloque_Acero* Bloque : ListaBloqueAcero) {
        if(Bloque)
        Bloque->Destroy();
    }
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

void AGameModeLevel3::CambiarEscenario(ETipoEscenario NuevoEscenario)
{
    if (GestorEscenarios)
    {
        GestorEscenarios->ConstruirEscenario(GetWorld(), NuevoEscenario);
    }

}
