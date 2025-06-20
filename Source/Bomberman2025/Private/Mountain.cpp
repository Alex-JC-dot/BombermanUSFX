// Fill out your copyright notice in the Description page of Project Settings.


#include "Mountain.h"

// Sets default values
AMountain::AMountain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

		Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
		RootComponent = Mesh;

		auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Artico/Motanas/scene.scene'"));
		if (MeshAsset.Object != nullptr)
		{
			Mesh->SetStaticMesh(MeshAsset.Object);
		}
		
		Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void AMountain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMountain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

