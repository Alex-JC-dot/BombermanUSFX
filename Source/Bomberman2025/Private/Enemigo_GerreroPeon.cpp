// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_GerreroPeon.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemigo_GerreroPeon::AEnemigo_GerreroPeon()
{
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaEnemigo(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Antiguo/Enemigos/Guerrero/Warrior.Warrior'"));
    if (MallaEnemigo.Succeeded())
    {
        GetMesh()->SetSkeletalMesh(MallaEnemigo.Object);

        GetMesh()->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
        GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> WalkAnim(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Antiguo/Enemigos/Guerrero/Armature_RunLegs.Armature_RunLegs'"));
    if (WalkAnim.Succeeded())
    {
        AnimacionCaminar = WalkAnim.Object;
    }


    static ConstructorHelpers::FObjectFinder<UAnimSequence> AtaqueObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Antiguo/Enemigos/Guerrero/Armature_Attack.Armature_Attack'"));
    if (AtaqueObj.Succeeded())
    {
        AnimacionAtaque = AtaqueObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> MoriroObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Antiguo/Enemigos/Guerrero/Armature_Dying.Armature_Dying'"));
    if (MoriroObj.Succeeded())
    {
        AnimacionMorir = MoriroObj.Object;
    }

    VidaMaxima = 40.0f; // Esqueleto 
    Vida = VidaMaxima;
    DanioAtaque = 6.0f; // Menos daño
}



void AEnemigo_GerreroPeon::BeginPlay()
{
    Super::BeginPlay();
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
  
    ReproducirAnimacionInicial();
}

float AEnemigo_GerreroPeon::GetDanio()
{
    return DanioAtaque;
}