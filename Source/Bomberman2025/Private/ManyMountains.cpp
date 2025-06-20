// Fill out your copyright notice in the Description page of Project Settings.


#include "ManyMountains.h"

// Sets default values
AManyMountains::AManyMountains()
{
 	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Artico/MasMontana/scene.scene'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	Mesh->SetWorldScale3D(FVector(300.0f, 400.0f, 300.0f));
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void AManyMountains::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AManyMountains::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

