// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_EsqueletoFinal.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "Navigation/PathFollowingComponent.h"
#include "Bomberman2025/Bomberman2025Character.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"



AEnemigo_EsqueletoFinal::AEnemigo_EsqueletoFinal()
{
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaEnemigo(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Cementerio/Enemigos/Jefe/Mutant_Swiping.Mutant_Swiping'"));
    if (MallaEnemigo.Succeeded())
    {
        
        GetMesh()->SetSkeletalMesh(MallaEnemigo.Object);
        GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, 0.0f));
        
    }
    static ConstructorHelpers::FObjectFinder<UAnimSequence> WalkAnim(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/Jefe/Unarmed_Walk_Forward__1_.Unarmed_Walk_Forward__1_'"));
    if (WalkAnim.Succeeded())
    {
        AnimacionCaminar = WalkAnim.Object;
    }


    static ConstructorHelpers::FObjectFinder<UAnimSequence> AtaqueObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/Jefe/Mutant_Swiping_Anim.Mutant_Swiping_Anim'"));
    if (AtaqueObj.Succeeded())
    {
        AnimacionAtaque = AtaqueObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> MoriroObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/Jefe/Dying.Dying'"));
    if (MoriroObj.Succeeded())
    {
        AnimacionMorir = MoriroObj.Object;
    }
    // Para que tenga IA automáticamente
    VidaMaxima = 400.0f; // Esqueleto 
    Vida = VidaMaxima;
    DanioAtaque = 1.0f; // Menos daño
    RangoAtaque = 100.0f;

    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = AAIController::StaticClass();
    GetCharacterMovement()->MaxWalkSpeed = 200.0f;
}



void AEnemigo_EsqueletoFinal::BeginPlay()
{
    Super::BeginPlay();
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.0f));
    GetMesh()->SetRelativeScale3D(FVector(2.5f, 2.5f, 2.5f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));

    ReproducirAnimacionInicial();

}

void AEnemigo_EsqueletoFinal::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bEstaMuerto || bEstaAtacando) return;

    AActor* Jugador = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (!Jugador) return;

    float Distancia = FVector::Dist(GetActorLocation(), Jugador->GetActorLocation());

    if (Distancia <= RangoAtaque)
    {
        AtacarJugador();
    }
    else if (Distancia <= RangoDeteccion)
    {
        PerseguirJugador(Jugador->GetActorLocation());
    }
}

void AEnemigo_EsqueletoFinal::PerseguirJugador(const FVector& Destino)
{
    AAIController* AIController = Cast<AAIController>(GetController());
    if (!AIController) return;

    FAIMoveRequest MoveRequest;
    MoveRequest.SetGoalLocation(Destino);
    MoveRequest.SetAcceptanceRadius(5.0f);

    FNavPathSharedPtr NavPath;
    AIController->MoveTo(MoveRequest, &NavPath);

    if (AnimacionCaminar && !bEstaCaminando)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
        bEstaCaminando = true;
    }
}

void AEnemigo_EsqueletoFinal::AtacarJugador()
{
    bEstaAtacando = true;
    bEstaCaminando = false;

    GetMesh()->Stop();

    if (AnimacionAtaque)
    {
        GetMesh()->PlayAnimation(AnimacionAtaque, false);
        float Duracion = AnimacionAtaque->GetPlayLength();

        GetWorldTimerManager().SetTimer(TemporizadorAtaque, this, &AEnemigo_EsqueletoFinal::TerminarAtaque, Duracion, false);
    }

    APawn* JugadorPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    ABomberman2025Character* JugadorRef = Cast<ABomberman2025Character>(JugadorPawn);

    if (JugadorRef)
    {
        JugadorRef->RecibirDano(DanioAtaque);
    }
}

void AEnemigo_EsqueletoFinal::TerminarAtaque()
{
    bEstaAtacando = false;

    if (!bEstaMuerto && AnimacionCaminar)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
        bEstaCaminando = true;
    }
}

void AEnemigo_EsqueletoFinal::RecibirDano(float Cantidad)
{
    if (bEstaMuerto || Cantidad <= 0.f) return;

    Vida -= Cantidad;

    if (Vida <= 0.f)
    {
        Vida = 0.f;
        bEstaMuerto = true;

        AAIController* AIController = Cast<AAIController>(GetController());
        if (AIController) AIController->StopMovement();

        GetCharacterMovement()->DisableMovement();
        SetLifeSpan(5.0f);

        if (AnimacionMorir)
        {
            GetMesh()->Stop();
            GetMesh()->PlayAnimation(AnimacionMorir, false);
        }
    }
}

void AEnemigo_EsqueletoFinal::ReproducirAnimacionInicial()
{
    if (AnimacionCaminar)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
        bEstaCaminando = true;
    }
}
