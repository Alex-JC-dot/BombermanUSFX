// Fill out your copyright notice in the Description page of Project Settings.


#include "Edificio1.h"

// Sets default values
AEdificio1::AEdificio1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Urbano/MasEdificio/Edificio3.Edificio3'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	Mesh->SetWorldScale3D(FVector(3.0f, 3.0f, 4.0f));

	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AEdificio1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEdificio1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

