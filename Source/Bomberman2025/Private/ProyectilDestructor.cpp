// Fill out your copyright notice in the Description page of Project Settings.


#include "ProyectilDestructor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "GameInstance_Datos.h"
#include "Bomberman2025//Bomberman2025Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProyectilDestructor::AProyectilDestructor()
{
    PrimaryActorTick.bCanEverTick = true;

    MallaProyectil = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaProyectil"));
    RootComponent = MallaProyectil;

    MallaProyectil->SetStaticMesh(ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Bomba/BombaProyectil/Proyectil.Proyectil'")).Object);
    MallaProyectil->SetWorldScale3D(FVector(0.1, 0.1, 0.1));
    if (!MallaProyectil->GetStaticMesh())
    {
       
        UE_LOG(LogTemp, Warning, TEXT("No se pudo cargar la malla del proyectil."));
    }
    static ConstructorHelpers::FObjectFinder<UParticleSystem> Particula(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
    if (Particula.Succeeded())
    {
        Explosion = Particula.Object.Get();
    }


    MallaProyectil->SetSimulatePhysics(true);
    MallaProyectil->SetCollisionProfileName("BlockAllDynamic");
    MallaProyectil->OnComponentHit.AddDynamic(this, &AProyectilDestructor::OnImpacto);
    // MallaProyectil->OnComponentHit.AddDynamic(this, &AProyectilDestructor::OnImpacto);

    MovimientoProyectil = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovimientoProyectil"));
    MovimientoProyectil->bShouldBounce = false;
    MovimientoProyectil->ProjectileGravityScale = 1.0f; // Asegura caída con gravedad
    MovimientoProyectil->InitialSpeed = 0.0f; // Deja que la gravedad lo arrastre
    static ConstructorHelpers::FObjectFinder<USoundBase> SonidoAsset(TEXT("/Script/Engine.SoundWave'/Game/StarterContent/Audio/Explosion01.Explosion01'")); // Ruta correcta para el sonido
    if (SonidoAsset.Succeeded())
    {
        Sonido = SonidoAsset.Object; // Asignación del sonido de colisión
    }
}

void AProyectilDestructor::BeginPlay()
{
    Super::BeginPlay();

    UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
    if (Datos)
    {
        Dano = Datos->ObtenerDanoProyectil();
    }
}

void AProyectilDestructor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AProyectilDestructor::OnImpacto(UPrimitiveComponent* Comp, AActor* OtroActor,
    UPrimitiveComponent* OtraComp, FVector Impulso, const FHitResult& Impacto)
{
    if (Explosion)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion, Impacto.ImpactPoint, FRotator::ZeroRotator);
    }

    // Aplica daño en radio de 300 unidades (ajusta según necesites)
    float RadioExplosion = 300.f;
    float DanoExplosion = 20.f;
    UGameplayStatics::ApplyRadialDamage(GetWorld(), DanoExplosion, Impacto.ImpactPoint, RadioExplosion,
        nullptr, TArray<AActor*>(), this, GetInstigatorController(), true);
    ABomberman2025Character* Player = Cast<ABomberman2025Character>(OtroActor);
    if (Player)
    {
        Player->RecibirDano(Dano);
        if (Sonido)
        {
            UGameplayStatics::PlaySoundAtLocation(this, Sonido, GetActorLocation(), 0.05f);
        }
    }
    Destroy();

}



