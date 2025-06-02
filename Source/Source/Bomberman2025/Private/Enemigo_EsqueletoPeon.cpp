// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_EsqueletoPeon.h"
#include "AIController.h"
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
    
    GetCharacterMovement()->MaxWalkSpeed = GetVelocidadMovimiento();
    
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
    // Para que tenga IA automáticamente
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = AAIController::StaticClass();
}
void AEnemigo_EsqueletoPeon::BeginPlay()
{
    Super::BeginPlay();
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    if (AnimacionCaminar)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
    }
    GetWorld()->GetTimerManager().SetTimer(TiempoMovimiento, this, &AEnemigo_EsqueletoPeon::SeguirJugador, 1.0f, true);
}

void AEnemigo_EsqueletoPeon::SeguirJugador()
{
    Mover();
}
