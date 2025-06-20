// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpExplosion.h"

// Sets default values
APowerUpExplosion::APowerUpExplosion()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaPoweUpRango(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/PowerUp/Bomba/Rango.Rango'"));
	if (MallaPoweUpRango.Succeeded())
	{
		Mesh->SetSkeletalMesh(MallaPoweUpRango.Object);
		Mesh->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
		Mesh->SetWorldScale3D(FVector(0.25, 0.25, 0.25));
	}
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	Collision->SetupAttachment(RootComponent);
	Collision->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic")); // Importante para que detecte overlaps
	// Conectamos al evento de colisi?n
	Collision->OnComponentBeginOverlap.AddDynamic(this, &APowerUpExplosion::OnOverlapBegin);
}

// Called when the game starts or when spawned
void APowerUpExplosion::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerUpExplosion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, 60 * DeltaTime, 0));
}

void APowerUpExplosion::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ABomberman2025Character* Player = Cast<ABomberman2025Character>(OtherActor))
	{
		Player->AlcanceExplosion += 1;

		Destroy();
	}


}

