// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_EsqueletoMago.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"



AEnemigo_EsqueletoMago::AEnemigo_EsqueletoMago()
{
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaEnemigo(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Urbano/Enemigos/Peon/DOUBT.DOUBT'"));
    if (MallaEnemigo.Succeeded())
    {
        GetMesh()->SetSkeletalMesh(MallaEnemigo.Object);
        GetMesh()->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
        GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    }
    static ConstructorHelpers::FObjectFinder<UAnimSequence> WalkAnim(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Urbano/Enemigos/Peon/DOUBT_Anim_Doubt_Armature_Doubt_ArmatureAction_001.DOUBT_Anim_Doubt_Armature_Doubt_ArmatureAction_001'"));
    if (WalkAnim.Succeeded())
    {
        AnimacionCaminar = WalkAnim.Object;
    }
    

    static ConstructorHelpers::FObjectFinder<UAnimSequence> AtaqueObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Urbano/Enemigos/Peon/DOUBT_Anim_Doubt_Armature_Doubt_ArmatureAction_005.DOUBT_Anim_Doubt_Armature_Doubt_ArmatureAction_005'"));
    if (AtaqueObj.Succeeded())
    {
        AnimacionAtaque = AtaqueObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> MoriroObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Urbano/Enemigos/Peon/DOUBT_Anim_Doubt_Armature_Doubt_ArmatureAction_006.DOUBT_Anim_Doubt_Armature_Doubt_ArmatureAction_006'"));
    if (MoriroObj.Succeeded())
    {
        AnimacionMorir = MoriroObj.Object;
    }
    // Para que tenga IA automáticamente

    VidaMaxima = 20.0f; // Esqueleto 
    Vida = VidaMaxima;
    DanioAtaque = 4.0f; // Menos daño
}


void AEnemigo_EsqueletoMago::BeginPlay()
{
    Super::BeginPlay();
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, 30.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    ReproducirAnimacionInicial();
   
}
float AEnemigo_EsqueletoMago::GetDanio()
{
    return DanioAtaque;
}


