// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoBase_GolemPeon.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"



AEnemigoBase_GolemPeon::AEnemigoBase_GolemPeon()
{
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaEnemigo(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Artico/Enemigo/Peon/Walkinganim.Walkinganim'"));
    if (MallaEnemigo.Succeeded())
    {
        GetMesh()->SetSkeletalMesh(MallaEnemigo.Object);

        GetMesh()->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
        GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> WalkAnim(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Artico/Enemigo/Peon/Walkinganim_Anim.Walkinganim_Anim'"));
    if (WalkAnim.Succeeded())
    {
        AnimacionCaminar = WalkAnim.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> AtaqueObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Artico/Enemigo/Peon/Standing_Torch_Melee_Attack_02.Standing_Torch_Melee_Attack_02'"));
    if (AtaqueObj.Succeeded())
    {
        AnimacionAtaque = AtaqueObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> MoriroObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Artico/Enemigo/Peon/Dying.Dying'"));
    if (MoriroObj.Succeeded())
    {
        AnimacionMorir = MoriroObj.Object;
    }
    VidaMaxima = 20.0f; // Esqueleto 
    Vida = VidaMaxima;
    DanioAtaque = 5.0f; // Menos daño
}

void AEnemigoBase_GolemPeon::BeginPlay()
{
    Super::BeginPlay();
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    ReproducirAnimacionInicial();
}

float AEnemigoBase_GolemPeon::GetDanio()
{
    return DanioAtaque;
}
