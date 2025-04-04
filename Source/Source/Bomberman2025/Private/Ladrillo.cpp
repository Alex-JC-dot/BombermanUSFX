// Fill out your copyright notice in the Description page of Project Settings.


#include "Ladrillo.h"

// Sets default values
ALadrillo::ALadrillo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("//Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	Mesh->SetWorldScale3D(FVector(2.7f, 2.7f, 2.7f));
	MovLadrilo = FVector(1.0f, 0.0f, 0.0f);  
	Velocidad = 200.0f;
	Tope = 5000.0f;

	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/Hechos/alley-brick-wall-ue/MaterialMOD1.MaterialMOD1'"));
	if (MaterialAsset.Object != nullptr) {

		Mesh->SetMaterial(0, MaterialAsset.Object);
	}
}

// Called when the game starts or when spawned
void ALadrillo::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}

// Called every frame
void ALadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float DistanciaRecorrida = FVector::Dist(PosicionInicial, GetActorLocation());
	if (DistanciaRecorrida < Tope) 
	{
		FVector NuevaPosicion = GetActorLocation() + (MovLadrilo * Velocidad * DeltaTime);
		SetActorLocation(NuevaPosicion);
	}

}

