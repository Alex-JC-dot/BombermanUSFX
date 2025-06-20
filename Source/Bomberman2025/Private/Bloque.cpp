// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"

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
	//Particula
	static ConstructorHelpers::FObjectFinder<UParticleSystem> Particula(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (Particula.Succeeded())
	{
		Explosion = Particula.Object.Get();
	}
}

void ABloque::Destruir()
{
	Destroy();
}



// Called when the game starts or when spawned
void ABloque::BeginPlay()
{
	Super::BeginPlay();
	

}
void ABloque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}
FString ABloque::GetNombreBloque()
{
	//Return the name of this Potion
	return NombreBloque;
}
