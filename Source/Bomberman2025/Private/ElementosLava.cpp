// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementosLava.h"

// Sets default values
AElementosLava::AElementosLava()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaDecoracion"));
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AElementosLava::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void AElementosLava::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AElementosLava::EstablecerMalla(UStaticMesh* Malla)
{
	if (Malla) {
		Mesh->SetStaticMesh(Malla);
	}
}

UStaticMesh* AElementosLava::MEshRuta(const FString& Ruta)
{
	return   Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *Ruta));
}

