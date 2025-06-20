// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoBase.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
//#include "IBombaObservable.h"
#include "Bomba.h"
#include "GameInstance_Datos.h"
#include "GameFramework/Character.h"
#include "Navigation/PathFollowingComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AIController.h"
#include "W_BarraVida.h"
#include "TimerManager.h"
//#include "Comportamiento_Escapar.h"
#include "Comportamiento_Patrullar.h"
#include "Comportamiento_Perseguir.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"

class UPawnSensingComponent;
class UEnemigoComportamiento;

// Sets default values
AEnemigoBase::AEnemigoBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass = AAIController::StaticClass();
    BarraDeVidaWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("BarraDeVidaWidget"));
    BarraDeVidaWidget->SetupAttachment(GetMesh());
    BarraDeVidaWidget->SetWidgetSpace(EWidgetSpace::World);
    BarraDeVidaWidget->SetDrawSize(FVector2D(100.f, 10.f));
    BarraDeVidaWidget->SetRelativeLocation(FVector(0.f, 0.f, 60.f)); 
    BarraDeVidaWidget->SetPivot(FVector2D(0.5f, 0.5f));
   
    static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClass(TEXT("/Game/GameModeCasero/UI/W_BarraEnemigo"));
    if (WidgetClass.Succeeded())
    {
        BarraDeVidaWidget->SetWidgetClass(WidgetClass.Class);
    }

}

// Called when the game starts or when spawned
void AEnemigoBase::BeginPlay()
{
	Super::BeginPlay();

    ComportamientoPatrullar = NewObject<UComportamiento_Patrullar>();
    ComportamientoPerseguir = NewObject<UComportamiento_Perseguir>();

    // Inicializar en modo patrulla
    CambiarComportamiento(EComportamiento::Patrullar);
    UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
    if (Datos)
    {
        Dano = Datos->ObtenerDanoEnemigo();
    }
}

// Called every frame
void AEnemigoBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (ComportamientoActual)
    {
        ComportamientoActual->EjecutarComportamiento(this);
    }
    if (!bEstaMuerto && !bEstaAtacando)
    {
        AActor* Jugador = ObtenerJugador();
        if (Jugador && FVector::Dist(GetActorLocation(), Jugador->GetActorLocation()) < RangoAtaque)
        {
            Atacar();
        }
    }
}

void AEnemigoBase::CambiarComportamiento(EComportamiento NuevoComportamiento)
{
    EstadoActual = NuevoComportamiento;

    switch (EstadoActual)
    {
    case EComportamiento::Patrullar:
        ComportamientoActual = ComportamientoPatrullar;
        break;
    case EComportamiento::Perseguir:
        ComportamientoActual = ComportamientoPerseguir;
        break;
    /*case EComportamiento::Escapar:
        ComportamientoActual = ComportamientoEscapar;
        break;*/
    default:
        break;
    }
}


bool AEnemigoBase::ObtenerPuntoAleatorioEnNavMesh(FVector& PuntoDestino)
{
    UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
    if (NavSys)
    {
        FNavLocation UbicacionAleatoria;
        if (NavSys->GetRandomPointInNavigableRadius(GetActorLocation(), 100.0f, UbicacionAleatoria))
        {
            PuntoDestino = UbicacionAleatoria.Location;
            return true;
        }
    }
    return false;
}

AActor* AEnemigoBase::ObtenerJugador() const
{
    return UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

FVector AEnemigoBase::GenerarPuntoAleatorio()
{
    UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
    if (!NavSys) return GetActorLocation();

    FNavLocation Resultado;
    bool Exito = NavSys->GetRandomReachablePointInRadius(GetActorLocation(), 800.f, Resultado);
    return Exito ? Resultado.Location : GetActorLocation();
}

//void AEnemigoBase::IniciarEscape()
//{
//    if (bEstaEscapando) return; // Ya está escapando, no repetir
//
//    bEstaEscapando = true;
//
//    EstadoAnterior = EstadoActual;
//    CambiarComportamiento(EComportamiento::Escapar);
//
//    // Después de 5 segundos, terminar escape
//    GetWorldTimerManager().SetTimer(TimerHandle_Escape, this, &AEnemigoBase::TerminarEscape, 5.f, false);
//}
//
//
//void AEnemigoBase::TerminarEscape()
//{
//    bEstaEscapando = false;
//
//    CambiarComportamiento(EstadoAnterior); // Regresa al comportamiento que tenía antes de escapar
//}


// Morir
void AEnemigoBase::RecibirDanio()
{
    if (bEstaMuerto) return;

    Vida -= Dano;
   
    Vida = FMath::Clamp(Vida, 0.f, VidaMaxima);

    float PorcentajeVida = Vida / VidaMaxima;

    if (BarraDeVidaWidget)
    {
        UW_BarraVida* WidgetVida = Cast<UW_BarraVida>(BarraDeVidaWidget->GetUserWidgetObject());
        if (WidgetVida)
        {
            WidgetVida->ActualizarBarraVida(PorcentajeVida);
        }
    }
    if (Vida <= 0)
    {
        bEstaMuerto = true;
        bEstaCaminando = false;

        if (AnimacionMorir)
        {
            GetMesh()->PlayAnimation(AnimacionMorir, false);
        }

        // Esperar 2 segundos y luego destruir
        GetWorld()->GetTimerManager().SetTimer(
            TemporizadorMuerte, this, &AEnemigoBase::Destruir, 2.0f, false);
    }
}


void AEnemigoBase::Destruir()
{
    if (GestorEnemigos)
    {
        GestorEnemigos->NotificarMuerte();
    }
 Destroy();
}

float AEnemigoBase::GetDanio()
{
    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Cyan, TEXT("Dabo defecto"));
    return 20.0f;
}
void AEnemigoBase::Atacar()
{
    if (bEstaAtacando || !AnimacionAtaque || bEstaMuerto)
        return;

    bEstaAtacando = true;
    bEstaCaminando = false;

    GetMesh()->Stop(); // Detiene animación actual
    GetMesh()->PlayAnimation(AnimacionAtaque, false);

    // Después de duración de la animación, volver al estado anterior
    float Duracion = AnimacionAtaque->GetPlayLength();
    GetWorldTimerManager().SetTimer(TemporizadorAtaque, this, &AEnemigoBase::TerminarAtaque, Duracion, false);
    ABomberman2025Character* JugadorRef = Cast<ABomberman2025Character>(ObtenerJugador());
    if (JugadorRef)
    {
        JugadorRef->RecibirDano(Dano);
    }

}
void AEnemigoBase::TerminarAtaque()
{
    bEstaAtacando = false;

    // Opcional: volver a caminar
    if (!bEstaMuerto && AnimacionCaminar)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
        bEstaCaminando = true;
    }
}
void AEnemigoBase::AlTerminarMovimiento(FAIRequestID RequestID, const FPathFollowingResult& Resultado)
{
    if (Resultado.Code != EPathFollowingResult::Success)
    {
        // Movimiento fallido, solo reaccionamos si está patrullando
        if (EstadoActual == EComportamiento::Patrullar && ComportamientoPatrullar)
        {
            UE_LOG(LogTemp, Warning, TEXT("Movimiento fallido, generando nuevo destino."));
            UComportamiento_Patrullar* ComportamientoPatrullarCast = Cast<UComportamiento_Patrullar>(ComportamientoActual);
            if (ComportamientoPatrullarCast)
            {
                ComportamientoPatrullarCast->ForzarNuevoDestino();
            }
        }
    }
}


void AEnemigoBase::ReproducirAnimacionInicial()
{
    if (AnimacionCaminar)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
        bEstaCaminando = true;
    }
}

void AEnemigoBase::AsignarGestor(AGestorEnemigos* Gestor)
{
    GestorEnemigos = Gestor;

}
