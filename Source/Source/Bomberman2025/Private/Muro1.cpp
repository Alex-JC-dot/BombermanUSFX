// Fill out your copyright notice in the Description page of Project Settings.


#include "Muro1.h"

// Sets default values
AMuro1::AMuro1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseComponent");
	RootComponent = Mesh;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));
	if (MeshAsset.Object != nullptr) {
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/Hechos/alley-brick-wall-ue/MaterialMOD1.MaterialMOD1'"));

}

// Called when the game starts or when spawned
void AMuro1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMuro1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

