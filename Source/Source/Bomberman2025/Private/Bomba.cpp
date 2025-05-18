// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomba.h"

// Sets default values
ABomba::ABomba()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	RootComponent = Mesh;
	auto Asset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Bomba/Bomba.Bomba'"));
	if (Asset.Object != nullptr) {

		Mesh->SetSkeletalMesh(Asset.Object);
	}
	EscalaTope = FVector(FMath::RandRange(4.0f*2,6.0f*2), FMath::RandRange(4.0f * 2, 6.0f * 2), FMath::RandRange(4.0f * 2, 6.0f * 2));
}

// Called when the game starts or when spawned
void ABomba::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CrecimientoVelocidad(DeltaTime);
	EscalaActual = GetActorScale3D();
	if (EscalaActual.X >= EscalaTope.X &&EscalaActual.Y >= EscalaTope.Y &&EscalaActual.Z >= EscalaTope.Z) {
		Activado = false;
		Destroy();
	}
	Crecimiento(DeltaTime);
}
void ABomba::CrecimientoVelocidad(float deltatime)
{	
	if (VelocidadActiva) {
		Velocidad += aceleracion*deltatime;

		if (Velocidad >= velocidadtope) {
			VelocidadActiva = false;
		}
	}
}


void ABomba::Crecimiento(float time)
{	
	if (!Activado) {
		return;
	}
	EscalaActual = GetActorScale3D();
	if (Activado) {
		EscalaActual = EscalaActual + FVector(time * Velocidad, time * Velocidad, time * Velocidad);
	}
	
	SetActorScale3D(EscalaActual);

}


