// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementosDesierto.h"

// Sets default values
AElementosDesierto::AElementosDesierto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaDecoracion"));
	RootComponent = Mesh;
	//Rutas
	RutaDesierto1 = TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Desierto/1Er_Desierto/Desierto.Desierto'");
	RutaDesierto2 = TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Desierto/3Er_Desierto/Desierto3.Desierto3'");
	RutaDesierto3 = TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Desierto/2Do_Desierto/Desierto3.Desierto3'");
	RutaCactus = TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Desierto/Cactus/Cactus.Cactus'");

}

// Called when the game starts or when spawned
void AElementosDesierto::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AElementosDesierto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AElementosDesierto::EstablecerMalla(UStaticMesh* Malla)
{
	if (Malla) {
		Mesh->SetStaticMesh(Malla);
	}
}

UStaticMesh* AElementosDesierto::MeshRuta(const FString& Ruta)
{
	return Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *Ruta));
}

