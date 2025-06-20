// Fill out your copyright notice in the Description page of Project Settings.


#include "ArbolJungla.h"

// Sets default values
AArbolJungla::AArbolJungla()
{
		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;

		Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
		RootComponent = Mesh;

		auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Jungla/Arboles/scene.scene'"));
		if (MeshAsset.Object != nullptr)
		{
			Mesh->SetStaticMesh(MeshAsset.Object);
		}
	

}

// Called when the game starts or when spawned
void AArbolJungla::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArbolJungla::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

