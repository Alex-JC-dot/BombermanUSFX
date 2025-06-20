// Fill out your copyright notice in the Description page of Project Settings.


#include "Bob2.h"

// Sets default values
ABob2::ABob2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh =CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset =ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Engine/EngineMeshes/Sphere.Sphere'"));
			if (MeshAsset.Object != nullptr)
			{
				Mesh->SetStaticMesh(MeshAsset.Object);
			}

			velociad = 800.0f;
			DIstanciaMaxima.Y = 400;
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
	Despegar(DeltaTime);
}

void ABob2::Despegar(float tiempo)
{
	FVector UbicacionActual=GetActorLocation();
	if (UbicacionActual.Y<=DIstanciaMaxima.Y) {
		UbicacionActual.Y += tiempo * velociad;
		SetActorLocation(UbicacionActual);
	}
	else
	{
		Destroy();
	}
	
}

