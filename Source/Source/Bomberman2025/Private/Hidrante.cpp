// Fill out your copyright notice in the Description page of Project Settings.


#include "Hidrante.h"

// Sets default values
AHidrante::AHidrante()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	{

		Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
		RootComponent = Mesh;

		auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Urbano/Decoraciones/FyreHy.FyreHy'"));
		if (MeshAsset.Object != nullptr)
		{
			Mesh->SetStaticMesh(MeshAsset.Object);
		}
		Mesh->SetWorldScale3D(FVector(1.3f, 1.3f, 1.3f));
		Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

}

// Called when the game starts or when spawned
void AHidrante::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHidrante::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

