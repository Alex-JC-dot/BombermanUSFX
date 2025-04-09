// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque.h"

// Sets default values
ABloque::ABloque()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	alturaMax = 1000;
	Subiendo = false;
	activado = false;
};

// Called when the game starts or when spawned
void ABloque::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABloque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!activado) return; 
		PosicionActual = GetActorLocation();
		if (PosicionActual.Z >= alturaMax) {
			Subiendo = false;
		}
		else if (PosicionActual.Z <= 0) {
			Subiendo = true;
		}
	
	// Mover el bloque
	MoverBloque(DeltaTime);
}
void ABloque::MoverBloque(float Tiempo)
{
	PosicionActual = GetActorLocation();
	if (Subiendo) {
		PosicionActual.Z += Tiempo * velocidad;
	}
	else {
		PosicionActual.Z -= Tiempo * velocidad;
	}
	SetActorLocation(PosicionActual);

}
