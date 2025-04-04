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

}

// Called when the game starts or when spawned
void ABloque::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABloque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoverBloque(DeltaTime);
}
void ABloque::IniciarMovimiento(FVector NuevaPosObjetivo, float Tiempo)
{
	PosInicial = GetActorLocation(); 
	PosFinal = NuevaPosObjetivo; 
	TiempoDeMovimiento = Tiempo;     
	TiempoTranscurrido = 0.0f;       
}
void ABloque::MoverBloque(float DeltaTime)
{
	if (TiempoTranscurrido < TiempoDeMovimiento)
	{
		// Calcula cuánto ha avanzado el bloque
		TiempoTranscurrido += DeltaTime;
		float Progreso = FMath::Clamp(TiempoTranscurrido / TiempoDeMovimiento, 0.0f, 1.0f);

		// Calcula la nueva posición
		FVector NuevaPos = FMath::Lerp(PosInicial, PosFinal , Progreso);
		SetActorLocation(NuevaPos);
	}
}

