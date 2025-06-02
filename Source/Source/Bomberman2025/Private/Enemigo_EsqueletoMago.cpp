// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_EsqueletoMago.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"



AEnemigo_EsqueletoMago::AEnemigo_EsqueletoMago()
{
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaEnemigo(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Cementerio/Enemigos/Mago/Lich.Lich'"));
    if (MallaEnemigo.Succeeded())
    {
        GetMesh()->SetSkeletalMesh(MallaEnemigo.Object);
        
        GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    }
    static ConstructorHelpers::FObjectFinder<UAnimSequence> WalkAnim(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/Mago/Lich_Anim_Lich_Esqueleto_Lich_Parado_Voando.Lich_Anim_Lich_Esqueleto_Lich_Parado_Voando'"));
    if (WalkAnim.Succeeded())
    {
        AnimacionCaminar = WalkAnim.Object;
    }
    
    GetCharacterMovement()->MaxWalkSpeed = GetVelocidadMovimiento();

    static ConstructorHelpers::FObjectFinder<UAnimSequence> AtaqueObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/Mago/Lich_Anim_Lich_Esqueleto_Lich_Ataque_Distancia.Lich_Anim_Lich_Esqueleto_Lich_Ataque_Distancia'"));
    if (AtaqueObj.Succeeded())
    {
        AnimacionAtaque = AtaqueObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> MoriroObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/Mago/Lich_Anim_Lich_Esqueleto_Lich_Ataque_Distancia.Lich_Anim_Lich_Esqueleto_Lich_Ataque_Distancia'"));
    if (MoriroObj.Succeeded())
    {
        AnimacionMorir = MoriroObj.Object;
    }
    // Para que tenga IA automáticamente
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = AAIController::StaticClass();
}

void AEnemigo_EsqueletoMago::BeginPlay()
{
    Super::BeginPlay();
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, 30.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    if (AnimacionCaminar)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
    }
    GetWorld()->GetTimerManager().SetTimer(TiempoMovimiento, this, &AEnemigo_EsqueletoMago::SeguirJugador, 1.0f, true);
}

void AEnemigo_EsqueletoMago::SeguirJugador()
{
    Mover();
}
