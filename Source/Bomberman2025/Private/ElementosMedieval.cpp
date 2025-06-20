// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementosMedieval.h"

// Sets default values
AElementosMedieval::AElementosMedieval()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaDecoracion"));
	RootComponent = Mesh;
	//Rutas
	RutaLago =TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Medieval/Lago/Lago.Lago'");
	RutaCastillo= TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Medieval/Castillo/Castillo.Castillo'");
	RutaCaverna = TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Medieval/Edificio/Caverna.Caverna'");
	RutaCasa = TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Medieval/Casa/scene.scene'");
	RutaMercado= TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Medieval/Tienda/Tienda.Tienda'");
	RutaPasto=TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Medieval/Casa/scene.scene'");
}

// Called when the game starts or when spawned
void AElementosMedieval::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AElementosMedieval::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AElementosMedieval::EstablecerMalla(UStaticMesh* Malla)
{
	if (Malla) {
		Mesh->SetStaticMesh(Malla);
	}
}

UStaticMesh* AElementosMedieval::MeshRuta(const FString& Ruta)
{

	return Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *Ruta));
}

