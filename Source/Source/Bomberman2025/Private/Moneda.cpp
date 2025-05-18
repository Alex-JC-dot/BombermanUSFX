// Fill out your copyright notice in the Description page of Project Settings.


#include "Moneda.h"

// Sets default values
AMoneda::AMoneda()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = Mesh;
	auto Asset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cylinder.SM_Cylinder'"));
	if (Asset.Object != nullptr) {

		Mesh->SetStaticMesh(Asset.Object);
	}

}

// Called when the game starts or when spawned
void AMoneda::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoneda::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float Rotacion=0.0f;
	if (Activado) {
		Rotacion += VelocidadRotacion * DeltaTime;
	}
	if (!Activado) {
		Rotacion -= VelocidadRotacion * DeltaTime;

	}
	AnguloActual += Rotacion;
	if (FMath::Abs(AnguloActual) >= AnguloMaximoRotacion)
	{
		Activado = !Activado;
	}
	FRotator NuevaRotacion = GetActorRotation();
	NuevaRotacion.Pitch += Rotacion;
	SetActorRotation(NuevaRotacion);
}

