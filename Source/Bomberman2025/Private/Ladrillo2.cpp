// Fill out your copyright notice in the Description page of Project Settings.


#include "Ladrillo2.h"

// Sets default values
ALadrillo2::ALadrillo2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("//Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	Mesh->SetWorldScale3D(FVector(1.2f, 1.2f, 1.2f));
	MoviLadrillo = FVector(0.0f, 0.0f, 1.0f);
	velocidad = 20.0f;
	Tope = 100.0f;
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/Hechos/alley-brick-wall-ue/MaterialMOD1.MaterialMOD1'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0,MaterialAsset.Object);
	}
}

// Called when the game starts or when spawned
void ALadrillo2::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ALadrillo2::Destruir, 60.0f, false);
	
}

// Called every frame
void ALadrillo2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ALadrillo2::Destruir()
{
	Destroy();

}

