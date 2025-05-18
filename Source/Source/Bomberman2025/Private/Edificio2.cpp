// Fill out your copyright notice in the Description page of Project Settings.


#include "Edificio2.h"

// Sets default values
AEdificio2::AEdificio2()
{

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Urbano/Vecindario/Vecindario.Vecindario'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	Mesh->SetWorldScale3D(FVector(10.0f,10.0f,12.0f));

	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void AEdificio2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEdificio2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

