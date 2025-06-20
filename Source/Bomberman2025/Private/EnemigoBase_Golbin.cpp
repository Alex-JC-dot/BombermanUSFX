// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoBase_Golbin.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"

AEnemigoBase_Golbin::AEnemigoBase_Golbin()
{
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaEnemigo(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Antiguo/Enemigos/Duende/Goblin.Goblin'"));
    if (MallaEnemigo.Succeeded())
    {
        GetMesh()->SetSkeletalMesh(MallaEnemigo.Object);

        GetMesh()->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));
        GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> WalkAnim(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Antiguo/Enemigos/Duende/Goblin_Anim_RunAnimGoblin.Goblin_Anim_RunAnimGoblin'"));
    if (WalkAnim.Succeeded())
    {
        AnimacionCaminar = WalkAnim.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> AtaqueObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Antiguo/Enemigos/Duende/Goblin_Anim_LightAttackAnimGoblin.Goblin_Anim_LightAttackAnimGoblin'"));
    if (AtaqueObj.Succeeded())
    {
        AnimacionAtaque = AtaqueObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> MoriroObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Antiguo/Enemigos/Duende/Goblin_Anim_DeathAnimGoblin.Goblin_Anim_DeathAnimGoblin'"));
    if (MoriroObj.Succeeded())
    {
        AnimacionMorir = MoriroObj.Object;
    }
    
    VidaMaxima = 20.0f; // Esqueleto 
    Vida = VidaMaxima;
    DanioAtaque = 3.0f; // Menos daño
}



void AEnemigoBase_Golbin::BeginPlay()
{
    Super::BeginPlay();
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    ReproducirAnimacionInicial();

}
float AEnemigoBase_Golbin::GetDanio()
{
    return DanioAtaque;
}



