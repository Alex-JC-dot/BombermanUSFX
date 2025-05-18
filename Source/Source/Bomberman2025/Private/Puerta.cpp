// Fill out your copyright notice in the Description page of Project Settings.


#include "Puerta.h"

// Sets default values
APuerta::APuerta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;
	{

		Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
		RootComponent = Mesh;

		auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Urbano/door/PuertaUrban.PuertaUrban'"));
		if (MeshAsset.Object != nullptr)
		{
			Mesh->SetStaticMesh(MeshAsset.Object);
		}
		Mesh->SetWorldScale3D(FVector(0.01f, 0.01f, 0.01f));
	
	}
}

// Called when the game starts or when spawned
void APuerta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuerta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

