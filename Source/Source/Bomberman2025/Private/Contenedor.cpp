// Fill out your copyright notice in the Description page of Project Settings.


#include "Contenedor.h"

// Sets default values
AContenedor::AContenedor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	{

		Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
		RootComponent = Mesh;

		auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Urbano/Decoraciones/Contenedor.Contenedor'"));
		if (MeshAsset.Object != nullptr)
		{
			Mesh->SetStaticMesh(MeshAsset.Object);
		}
		Mesh->SetWorldScale3D(FVector(0.8f, 0.8f, 0.8f));

		

	}
}

// Called when the game starts or when spawned
void AContenedor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AContenedor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

