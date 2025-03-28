// Fill out your copyright notice in the Description page of Project Settings.


#include "HierarchyActor.h"

// Sets default values
AHierarchyActor::AHierarchyActor()
	: Root(nullptr), ChildSceneComponent(nullptr), BoxOne(nullptr), BoxTwo(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>("Root"); // Crear el componente raíz
	RootComponent = Root;

	ChildSceneComponent =CreateDefaultSubobject<USceneComponent>("ChildSceneComponent");
	BoxOne =CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");
	BoxTwo =CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");
	auto MeshAsset =ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Pokeball/Pokeball.Pokeball'"));
			if (MeshAsset.Object != nullptr)
			{
				BoxOne->SetStaticMesh(MeshAsset.Object);
				BoxTwo->SetStaticMesh(MeshAsset.Object);
			}
	RootComponent = Root;
	BoxOne->SetupAttachment(Root);
	BoxTwo->SetupAttachment(ChildSceneComponent);
	ChildSceneComponent->SetupAttachment(Root);
	ChildSceneComponent->SetRelativeTransform
	(FTransform(FRotator(0, 0, 0), FVector(250, 0, 0),
		FVector(0.1f)));

}

// Called when the game starts or when spawned
void AHierarchyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHierarchyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

