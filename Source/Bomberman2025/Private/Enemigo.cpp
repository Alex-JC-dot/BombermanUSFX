// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"

// Sets default values
AEnemigo::AEnemigo()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
		/*
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Personje"));
	Mesh->SetupAttachment(RootComponent);

	auto Asset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.Blueprint'/Game/Hechos/Equeletos/source/Digglet.Digglet'"));
	if (Asset.Object != nullptr) {
		Mesh->SetStaticMesh(Asset.Object);
	}
	*/
}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemigo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

