// Fill out your copyright notice in the Description page of Project Settings.


#include "Explosion.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Bloque.h"
#include "Enemigo.h"
#include "Enemigo_EsqueletoFinal.h"
#include "Enemigo_EsqueletoPeon.h"
#include "FinalBoss.h"
#include "GameInstance_Datos.h"
#include "EnemigoBase.h"
#include "Bomberman2025/Bomberman2025Character.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimSequence.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h" 

// Sets default values
AExplosion::AExplosion()
{
	PrimaryActorTick.bCanEverTick = true;

	// Crear y configurar el mesh de la explosión
	ExplosionMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ExplosionMesh"));
	RootComponent = ExplosionMesh;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Bomba/Explosion/scene.scene'"));
	if (MeshAsset.Succeeded())
	{
		ExplosionMesh->SetSkeletalMesh(MeshAsset.Object);
		ExplosionMesh->SetWorldScale3D(FVector(0.03f, 0.03f, 0.025f));
		ExplosionMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -23.0f));
	}

	static ConstructorHelpers::FObjectFinder<UAnimSequence> Anim(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Bomba/Explosion/scene_Anim.scene_Anim'"));
	if (Anim.Succeeded())
	{
		ExplosionAnimation = Anim.Object;
		ExplosionMesh->SetAnimation(ExplosionAnimation);
	}

	ExplosionMesh->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	ExplosionMesh->SetComponentTickEnabled(true);
	ExplosionMesh->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;

	// Crear y configurar la caja de colisión
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("AreaExplosion"));
	BoxComp->SetupAttachment(RootComponent);
	BoxComp->SetBoxExtent(FVector(3000.0f, 3000.0f, 5000.0f));
	BoxComp->SetRelativeLocation(FVector(0.0f, 0.0f, 500.0f));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComp->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	BoxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	BoxComp->SetGenerateOverlapEvents(true);

	// Conectar el evento de colisión
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AExplosion::OnOverlapBegin);

	// Cargar el sonido
	static ConstructorHelpers::FObjectFinder<USoundBase> SonidoAsset(TEXT("/Script/Engine.SoundWave'/Game/StarterContent/Audio/Fire_Sparks01.Fire_Sparks01'"));
	if (SonidoAsset.Succeeded())
	{
		Sonido = SonidoAsset.Object;
	}
}


// Called when the game starts or when spawned
void AExplosion::BeginPlay()
{
	Super::BeginPlay();
	// Reproducir la animación en bucle
	if (ExplosionMesh && ExplosionAnimation)
	{
		ExplosionMesh->PlayAnimation(ExplosionAnimation, true); // true = loop
	
	}
	UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (Datos)
	{
		dano = Datos->ObtenerDanoExplosion();
	}
}

// Called every frame
void AExplosion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//DrawDebugBox(
	//	GetWorld(),
	//	BoxComp->GetComponentLocation(),            // Centro de la caja
	//	BoxComp->GetScaledBoxExtent(),              // Tamaño de la caja
	//	BoxComp->GetComponentQuat(),                // Rotación
	//	FColor::Red,                                // Color
	//	false,                                      // Persistente
	//	-1.f,                                       // Tiempo de vida (negativo = un solo frame)
	//	0,                                          // Profundidad
	//	5                                           // Grosor
	//);
}

void AExplosion::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	// Verifica si el actor afectado es un bloque
	ABloque* Bloque = Cast<ABloque>(OtherActor);
	if (Bloque && Bloque->Destructible)
	{
		Bloque->Destruir(); // Llama a la función virtual que será diferente en cada hijo
	}

	AEnemigo* Enemigo = Cast<AEnemigo>(OtherActor);
	if (Enemigo)
	{
		Enemigo->ExplosionesRecibidas++;
		if (Enemigo) {
			Enemigo->Destruir();
		}
	}
	ABomberman2025Character* Personaje = Cast<ABomberman2025Character>(OtherActor);
	if (Personaje)
	{
		Personaje->RecibirDano(dano);
	}

	AEnemigoBase* EnemigoBase = Cast<AEnemigoBase>(OtherActor);
	if (EnemigoBase)
	{
		EnemigoBase->RecibirDanio();
		 
	}

	AFinalBoss* EnemigoFinal = Cast<AFinalBoss>(OtherActor);
	if (EnemigoFinal)
	{
		EnemigoFinal->RecibirDano(50.0f);
	}

	AEnemigo_EsqueletoPeon* EnemigoEsqueeltoPeon = Cast<AEnemigo_EsqueletoPeon>(OtherActor);
	if (EnemigoEsqueeltoPeon)
	{
		EnemigoEsqueeltoPeon->RecibirDano(40.0f);
	}

	AEnemigo_EsqueletoFinal* EnemigoEsqueletoFinal = Cast<AEnemigo_EsqueletoFinal>(OtherActor);
	if (EnemigoEsqueletoFinal)
	{
		EnemigoEsqueletoFinal->RecibirDano(40.0f);
	}
}



