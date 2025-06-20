// Fill out your copyright notice in the Description page of Project Settings.


#include "IceCulter2.h"

// Sets default values
AIceCulter2::AIceCulter2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Artico/Ice_Cluster2/scene.scene'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}

	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AIceCulter2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIceCulter2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

