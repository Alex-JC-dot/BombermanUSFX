// Fill out your copyright notice in the Description page of Project Settings.


#include "Dulce.h"

// Sets default values
ADulce::ADulce()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = Mesh;
	auto Asset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cylinder.SM_Cylinder'"));
	if (Asset.Object != nullptr) {

		Mesh->SetStaticMesh(Asset.Object);
	}
}

// Called when the game starts or when spawned
void ADulce::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADulce::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

