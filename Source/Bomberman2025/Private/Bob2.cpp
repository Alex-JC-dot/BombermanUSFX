// Fill out your copyright notice in the Description page of Project Settings.


#include "Bob2.h"

// Sets default values
ABob2::ABob2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh =CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset =ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));
			if (MeshAsset.Object != nullptr)
			{
				Mesh->SetStaticMesh(MeshAsset.Object);
			}
}

// Called when the game starts or when spawned
void ABob2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABob2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

