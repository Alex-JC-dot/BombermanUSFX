// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderHordaHielo.h"
#include "EnemigoBase_Golem.h"
#include "EnemigoBase_GolemPeon.h"


// Sets default values
ABuilderHordaHielo::ABuilderHordaHielo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Ubicacion_Inicial = FVector(-3994.488813, -3997.341838, 0.0f);
}

// Called when the game starts or when spawned
void ABuilderHordaHielo::BeginPlay()
{
	Super::BeginPlay();
	Horda = GetWorld()->SpawnActor<AHordaEnemigos>(AHordaEnemigos::StaticClass());
	Laberinto = GetWorld()->SpawnActor<ALaberintoTerminado>(ALaberintoTerminado::StaticClass());
}

// Called every frame
void ABuilderHordaHielo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderHordaHielo::ContruirEnemigoPeon(int cantidad)
{
	MezclarPosicion();


	for (int i = 0; i < Laberinto->MapaLaberinto3.Num(); i++) {
		for (int j = 0; j < Laberinto->MapaLaberinto3[i].Num(); j++) {
			int valor = Laberinto->MapaLaberinto3[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f) + FVector(200.0f, 200.0f, 0.0f);
			if (valor == 0) {
				PosicionLibre.Add(Posicion_Actual);
			}
		}

	}
	for (int i = 0; i < PosicionLibre.Num(); i++) {
		int RandIndex = FMath::RandRange(i, PosicionLibre.Num() - 1); PosicionLibre.Swap(i, RandIndex);
	}

	int MaxSpawn = FMath::Min(cantidad, PosicionLibre.Num());
	for (int i = 0; i < MaxSpawn; i++) {
		GetWorld()->SpawnActor<AEnemigoBase_GolemPeon>(AEnemigoBase_GolemPeon::StaticClass(), PosicionLibre[i], FRotator::ZeroRotator);
	}

}

void ABuilderHordaHielo::ContruirJefe(int cantidad)
{
	MezclarPosicion();

	int MaxSpawn = FMath::Min(cantidad, PosicionLibre.Num());
	for (int i = 0; i < MaxSpawn; i++) {
		GetWorld()->SpawnActor<AEnemigoBase_Golem>(AEnemigoBase_Golem::StaticClass(), PosicionLibre[i], FRotator::ZeroRotator);
	}



}



void ABuilderHordaHielo::ConstruirEnemigoMagico(int cantidad)
{



}

void ABuilderHordaHielo::MezclarPosicion()
{
	{
		for (int i = 0; i < PosicionLibre.Num(); i++) {
			int RandIndex = FMath::RandRange(i, PosicionLibre.Num() - 1);
			PosicionLibre.Swap(i, RandIndex);
		}

	}

}

AHordaEnemigos* ABuilderHordaHielo::GetHorda()
{
	return Horda;
}


