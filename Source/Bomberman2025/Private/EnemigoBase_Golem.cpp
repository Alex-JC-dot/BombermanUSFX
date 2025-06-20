// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoBase_Golem.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"




AEnemigoBase_Golem::AEnemigoBase_Golem()
{
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaEnemigo(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Artico/Enemigo/Golem/Falling_Back_Death__1_.Falling_Back_Death__1_'"));
    if (MallaEnemigo.Succeeded())
    {
        GetMesh()->SetSkeletalMesh(MallaEnemigo.Object);

        GetMesh()->SetRelativeScale3D(FVector(300.0, 300.0, 300.0));
        GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> WalkAnim(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Artico/Enemigo/Golem/Unarmed_Run_Forward.Unarmed_Run_Forward'"));
    if (WalkAnim.Succeeded())
    {
        AnimacionCaminar = WalkAnim.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> AtaqueObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Artico/Enemigo/Golem/Standing_Torch_Melee_Attack_02.Standing_Torch_Melee_Attack_02'"));
    if (AtaqueObj.Succeeded())
    {
        AnimacionAtaque = AtaqueObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> MoriroObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Artico/Enemigo/Golem/Falling_Back_Death__1__Anim.Falling_Back_Death__1__Anim'"));
    if (MoriroObj.Succeeded())
    {
        AnimacionMorir = MoriroObj.Object;
    }
    // Para que tenga IA automáticamente
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = AAIController::StaticClass();

}



void AEnemigoBase_Golem::BeginPlay()
{
    Super::BeginPlay();
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    ReproducirAnimacionInicial();

}

float AEnemigoBase_Golem::GetDanio()
{
    return DanioAtaque;
}
