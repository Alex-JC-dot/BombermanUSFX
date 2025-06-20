// Fill out your copyright notice in the Description page of Project Settings.


#include "Planta.h"

// Sets default values
APlanta::APlanta()
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Jungla/Plantitas/scene.scene'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void APlanta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlanta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

