// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_EsqueletoPeon.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "Navigation/PathFollowingComponent.h"
#include "Bomberman2025/Bomberman2025Character.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"


AEnemigo_EsqueletoPeon::AEnemigo_EsqueletoPeon()
{
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaEnemigo(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Cementerio/Enemigos/Peon/Skeleton.Skeleton'"));
    if (MallaEnemigo.Succeeded())
    {
        GetMesh()->SetSkeletalMesh(MallaEnemigo.Object);
       
        GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> WalkAnim(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/Peon/Skeleton_Anim_Skeleton_Bones_Esquelto_Caminhar.Skeleton_Anim_Skeleton_Bones_Esquelto_Caminhar'"));
    if (WalkAnim.Succeeded())
    {
        AnimacionCaminar = WalkAnim.Object;
    }
    
    
    static ConstructorHelpers::FObjectFinder<UAnimSequence> AtaqueObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/Peon/Skeleton_Anim_Skeleton_Bones_Esqueleto_Atacar_2.Skeleton_Anim_Skeleton_Bones_Esqueleto_Atacar_2'"));
    if (AtaqueObj.Succeeded())
    {
        AnimacionAtaque = AtaqueObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> MoriroObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/Peon/Skeleton_Anim_Skeleton_Bones_Esqueleto_Morrer.Skeleton_Anim_Skeleton_Bones_Esqueleto_Morrer'"));
    if (MoriroObj.Succeeded())
    {
        AnimacionMorir = MoriroObj.Object;
    }
   
    VidaMaxima = 20.0f; // Esqueleto 
    Vida = VidaMaxima;
    DanioAtaque = 5.0f; // Menos daño

    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = AAIController::StaticClass();

    
    GetCharacterMovement()->MaxWalkSpeed = 240.0f;

}




void AEnemigo_EsqueletoPeon::BeginPlay()
{
    Super::BeginPlay();
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));

    ReproducirAnimacionInicial();
 
}

void AEnemigo_EsqueletoPeon::Tick(float DeltaTime)
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

void AEnemigo_EsqueletoPeon::PerseguirJugador(const FVector& Destino)
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

void AEnemigo_EsqueletoPeon::AtacarJugador()
{
    bEstaAtacando = true;
    bEstaCaminando = false;

    GetMesh()->Stop();

    if (AnimacionAtaque)
    {
        GetMesh()->PlayAnimation(AnimacionAtaque, false);
        float Duracion = AnimacionAtaque->GetPlayLength();

        GetWorldTimerManager().SetTimer(TemporizadorAtaque, this, &AEnemigo_EsqueletoPeon::TerminarAtaque, Duracion, false);
    }

    APawn* JugadorPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    ABomberman2025Character* JugadorRef = Cast<ABomberman2025Character>(JugadorPawn);

    if (JugadorRef)
    {
        JugadorRef->RecibirDano(DanioAtaque);
    }
}

void AEnemigo_EsqueletoPeon::TerminarAtaque()
{
    bEstaAtacando = false;

    if (!bEstaMuerto && AnimacionCaminar)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
        bEstaCaminando = true;
    }
}

void AEnemigo_EsqueletoPeon::RecibirDano(float Cantidad)
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

void AEnemigo_EsqueletoPeon::ReproducirAnimacionInicial()
{
    if (AnimacionCaminar)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
        bEstaCaminando = true;
    }
}
