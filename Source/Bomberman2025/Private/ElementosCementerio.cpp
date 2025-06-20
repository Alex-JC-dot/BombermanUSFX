// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementosCementerio.h"

// Sets default values
AElementosCementerio::AElementosCementerio()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaDecoracion"));
	RootComponent = Mesh;
	//Rutas
	RutaIglesia = TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Cementerio/Iglesia/Iglesia.Iglesia'");
	RutaLapida1 = TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Cementerio/Lapida3/Cementerio3.Cementerio3'");
	RutaCalavera= TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Cementerio/Calavera/Calavera.Calavera'");
	RutaTumba = TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Cementerio/Tumba/Tumba.Tumba'");
}

// Called when the game starts or when spawned
void AElementosCementerio::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AElementosCementerio::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AElementosCementerio::EstablecerMalla(UStaticMesh* Malla)
{
	if (Malla) {
		Mesh->SetStaticMesh(Malla);
	}
}

UStaticMesh* AElementosCementerio::MeshRuta(const FString& Ruta)
{
	return Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *Ruta));
}

