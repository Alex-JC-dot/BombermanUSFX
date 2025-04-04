// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueAcero3.h"

// Sets default values
ABloqueAcero3::ABloqueAcero3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseComponent");
	RootComponent = Mesh;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));
	if (MeshAsset.Object != nullptr) {
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void ABloqueAcero3::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloqueAcero3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

