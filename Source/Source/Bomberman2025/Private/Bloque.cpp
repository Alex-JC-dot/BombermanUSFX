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
	Malla = Mesh->GetStaticMesh();
	
}

// Called when the game starts or when spawned
void ABloque::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
	

}
void ABloque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(Encendido&&Funcion){
	Funcion(DeltaTime);
	}
}
void ABloque::MovHorizontal(float time)
{
	PosicionActual = GetActorLocation();
	if (PosicionActual.Y >= 400.0f + PosicionInicial.Y) {
		Activado = false;
	}
	else if (PosicionActual.Y <= PosicionInicial.Y - 400.0f) {
		Activado = true;
	}
	if (Activado) {
		PosicionActual.Y += time * velocidad;
	}
	else
	{
		PosicionActual.Y -= time * velocidad;
	}

	SetActorLocation(PosicionActual);

}
void ABloque::MovVertical(float Tiempo)
{
	PosicionActual = GetActorLocation();
	if (PosicionActual.Z >= AlturaMax) {
		Activado = false;
	}
	else if(PosicionActual.Z<=0)
	{
		Activado = true;
	}
	if (Activado) {
		PosicionActual.Z += Tiempo * velocidad;
	}
	else {
		PosicionActual.Z -= Tiempo * velocidad;
	}
	SetActorLocation(PosicionActual);

}
FString ABloque::GetNombreBloque()
{
	//Return the name of this Potion
	return NombreBloque;
}