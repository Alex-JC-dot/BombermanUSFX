// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_EsqueletoFinal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"



AEnemigo_EsqueletoFinal::AEnemigo_EsqueletoFinal()
{
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaEnemigo(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Cementerio/Enemigos/Jefe/Mutant_Swiping.Mutant_Swiping'"));
    if (MallaEnemigo.Succeeded())
    {
        ;
        GetMesh()->SetSkeletalMesh(MallaEnemigo.Object);
        GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, 0.0f));
        
    }
    static ConstructorHelpers::FObjectFinder<UAnimSequence> WalkAnim(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/Jefe/Unarmed_Walk_Forward__1_.Unarmed_Walk_Forward__1_'"));
    if (WalkAnim.Succeeded())
    {
        AnimacionCaminar = WalkAnim.Object;
    }

    GetCharacterMovement()->MaxWalkSpeed = GetVelocidadMovimiento();

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
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = AAIController::StaticClass();
}




void AEnemigo_EsqueletoFinal::BeginPlay()
{
    Super::BeginPlay();
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -85.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    GetMesh()->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
    if (AnimacionCaminar)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
    }
    GetWorld()->GetTimerManager().SetTimer(TiempoMovimiento, this, &AEnemigo_EsqueletoFinal::SeguirJugador, 1.0f, true);
}

void AEnemigo_EsqueletoFinal::SeguirJugador()
{
    Mover();
}