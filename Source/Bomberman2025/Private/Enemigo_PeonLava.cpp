// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_PeonLava.h"

AEnemigo_PeonLava::AEnemigo_PeonLava() 
{
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaEnemigo(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Lava/Enemigo/Breathing_Idle.Breathing_Idle'"));
    if (MallaEnemigo.Succeeded())
    if (MallaEnemigo.Succeeded())
    {
        GetMesh()->SetSkeletalMesh(MallaEnemigo.Object);

        GetMesh()->SetRelativeScale3D(FVector(100.0f, 100.0f, 100.0f));
        GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> WalkAnim(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Lava/Enemigo/Breathing_Idle.Breathing_Idle'"));
    if (WalkAnim.Succeeded())
    {
        AnimacionCaminar = WalkAnim.Object;
    }


    static ConstructorHelpers::FObjectFinder<UAnimSequence> AtaqueObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Lava/Enemigo/Mutant_Punch.Mutant_Punch'"));
    if (AtaqueObj.Succeeded())
    {
        AnimacionAtaque = AtaqueObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> MoriroObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Lava/Enemigo/Mutant_Dying.Mutant_Dying'"));
    if (MoriroObj.Succeeded())
    {
        AnimacionMorir = MoriroObj.Object;
    }

    VidaMaxima = 40.0f; // Esqueleto 
    Vida = VidaMaxima;
    DanioAtaque = 6.0f; // Menos daño
}

void AEnemigo_PeonLava::BeginPlay()
{

    Super::BeginPlay();
    GetMesh()->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));

    ReproducirAnimacionInicial();

}

float AEnemigo_PeonLava::GetDanio()
{
    return DanioAtaque;
}
