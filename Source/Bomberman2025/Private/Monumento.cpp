// Fill out your copyright notice in the Description page of Project Settings.


#include "Monumento.h"

// Sets default values
AMonumento::AMonumento()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Jungla/Monumentos/scene.scene'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}

}

// Called when the game starts or when spawned
void AMonumento::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonumento::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

