// Fill out your copyright notice in the Description page of Project Settings.


#include "Jaguar.h"
#include "Animation/AnimationAsset.h"
// Sets default values
AJaguar::AJaguar()
{
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = Mesh;
	auto Asset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Jungla/Animales/scene.scene'"));
	if (Asset.Object != nullptr) {

		Mesh->SetSkeletalMesh(Asset.Object);
	}
	Mesh->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	
	static ConstructorHelpers::FObjectFinder<UAnimationAsset> AnimAsset(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Jungla/Animales/scene_Anim.scene_Anim'"));
	if (AnimAsset.Succeeded())
	{
		// Esto sí aparece en "Anim To Play" en el editor
		Mesh->SetAnimation(AnimAsset.Object);

		// Esto la reproduce automáticamente en loop
		Mesh->PlayAnimation(AnimAsset.Object, true);
	}
}
// Called when the game starts or when spawned
void AJaguar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJaguar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

