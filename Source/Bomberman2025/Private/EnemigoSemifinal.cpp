// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoSemifinal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "ProyectilDestructor.h"

// Sets default values
AEnemigoSemifinal::AEnemigoSemifinal()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
   //Ruta Propia
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    RootComponent = Mesh;
    auto Asset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Bomba/EnemigoVolador/PirataShip.PirataShip'"));
    if (Asset.Object != nullptr) {

        Mesh->SetStaticMesh(Asset.Object);
        Mesh->SetWorldScale3D(FVector(0.3, 0.3, 0.3));

    }


    SaludActual = SaludMaxima;
    FaseActual = EFaseDestructor::Fase1;
    TiempoVueloMax = 20.0f;
    TiempoTierraMax = 15.0f;
    IntervaloProyectil = 2.0f;

    GetCharacterMovement()->MaxWalkSpeed = VelocidadTierra;

    //ruta del proyectil es como colocar malla osea un direccion de memoria

    ClaseProyectil = AProyectilDestructor::StaticClass();

}

void AEnemigoSemifinal::BeginPlay()
{
    Super::BeginPlay();
    BuscarJugador();
    EntrarEnVuelo();
}

void AEnemigoSemifinal::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    GestionarVueloYTiempo(DeltaTime);
    ActualizarFase();
}

void AEnemigoSemifinal::BuscarJugador()
{
    Jugador = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}


void AEnemigoSemifinal::ActualizarFase()
{
    float Porcentaje = SaludActual / SaludMaxima;

    if (Porcentaje <= 0.25f && FaseActual != EFaseDestructor::Fase3)
    {
        CambiarFase(EFaseDestructor::Fase3);
    }
    else if (Porcentaje <= 0.5f && FaseActual != EFaseDestructor::Fase2)
    {
        CambiarFase(EFaseDestructor::Fase2);
    }
}

void AEnemigoSemifinal::CambiarFase(EFaseDestructor NuevaFase)
{
    FaseActual = NuevaFase;

    switch (FaseActual)
    {
    case EFaseDestructor::Fase1:
        TiempoVueloMax = 20.0f;
        TiempoTierraMax = 15.0f;
        IntervaloProyectil = 3.0f;
        break;
    case EFaseDestructor::Fase2:
        TiempoVueloMax = 30.0f;
        TiempoTierraMax = 10.0f;
        IntervaloProyectil = 3.0f;
        break;
    case EFaseDestructor::Fase3:
        TiempoVueloMax = 35.0f;
        TiempoTierraMax = 10.0f;
        IntervaloProyectil = 2.0f;
        break;
    }

    if (bEnVuelo)
    {
        IniciarTemporizadorProyectil(IntervaloProyectil);
    }
}

void AEnemigoSemifinal::GestionarVueloYTiempo(float DeltaTime)
{
    if (bEnVuelo)
    {
        TiempoEnVuelo += DeltaTime;
        FVector Destino = ObtenerPosicionEncimaJugador();
        SetActorLocation(FVector(Destino.X, Destino.Y, AlturaVuelo));

        if (TiempoEnVuelo >= TiempoVueloMax)
        {
            EntrarEnTierra();
        }
    }
    else
    {
        TiempoEnTierra += DeltaTime;
        PerseguirJugador();

        if (TiempoEnTierra >= TiempoTierraMax)
        {
            EntrarEnVuelo();
        }
    }
}

void AEnemigoSemifinal::EntrarEnVuelo()
{
    bEnVuelo = true;
    TiempoEnVuelo = 0.0f;
    GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
    IniciarTemporizadorProyectil(IntervaloProyectil);
}

void AEnemigoSemifinal::EntrarEnTierra()
{
    bEnVuelo = false;
    TiempoEnTierra = 0.0f;
    GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
    DetenerTemporizadorProyectil();
}

void AEnemigoSemifinal::PerseguirJugador()
{
    if (Jugador)
    {
        FVector Destino = Jugador->GetActorLocation();
        FVector Direccion = (Destino - GetActorLocation()).GetSafeNormal();
        AddMovementInput(Direccion);
    }
}

FVector AEnemigoSemifinal::ObtenerPosicionEncimaJugador() const
{
    if (Jugador)
    {
        FVector Pos = Jugador->GetActorLocation();
        return FVector(Pos.X, Pos.Y, AlturaVuelo);
    }
    return GetActorLocation();
}

void AEnemigoSemifinal::LanzarProyectil()
{
    if (!ClaseProyectil) return;

    FVector PosicionSpawn = FVector(0.f, 200.f, 0.0f)+ GetActorLocation() - FVector(0.f, 0.f, 100.f); // justo debajo del enemigo
    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.Instigator = GetInstigator();

    GetWorld()->SpawnActor<AActor>(ClaseProyectil, PosicionSpawn, FRotator::ZeroRotator, SpawnParams);
 
}


void AEnemigoSemifinal::IniciarTemporizadorProyectil(float Intervalo)
{
    GetWorld()->GetTimerManager().SetTimer(TimerProyectil, this, &AEnemigoSemifinal::LanzarProyectil, Intervalo, true);
}

void AEnemigoSemifinal::DetenerTemporizadorProyectil()
{
    GetWorld()->GetTimerManager().ClearTimer(TimerProyectil);
}

void AEnemigoSemifinal::RecibirDano(float Cantidad)
{
    if (bEstaMuerto) return;

    SaludActual -= Cantidad;

    if (SaludActual <= 0)
    {
        bEstaMuerto = true;
        bEstaCaminando = false;

        DetenerTemporizadorProyectil();
        GetCharacterMovement()->DisableMovement();

        Destroy();
    }
}
