// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementosAntiguo.h"

// Sets default values
AElementosAntiguo::AElementosAntiguo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaDecoracion"));
	RootComponent = Mesh;

	RutaRodas= TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Antiguo/ColosoRodas/Rodas.Rodas'");
	RutaRuinas=TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Antiguo/Ruina/Ruina.Ruina'");
	RutaMonumento= TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Antiguo/TemploSAGRADO/TemploSagrado.TemploSagrado'");

}

// Called when the game starts or when spawned
void AElementosAntiguo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AElementosAntiguo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AElementosAntiguo::EstablecerMalla(UStaticMesh* Malla)
{
	if (Malla) {
		Mesh->SetStaticMesh(Malla);
	}
}

UStaticMesh* AElementosAntiguo::MeshRuta(const FString& Ruta)
{
	return Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *Ruta));;
}

