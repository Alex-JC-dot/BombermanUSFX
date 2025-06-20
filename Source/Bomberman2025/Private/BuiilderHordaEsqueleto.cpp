// Fill out your copyright notice in the Description page of Project Settings.


#include "BuiilderHordaEsqueleto.h"
#include "Enemigo_EsqueletoFinal.h"
#include "Enemigo_EsqueletoMago.h"
#include "Enemigo_EsqueletoPeon.h"

// Sets default values
ABuiilderHordaEsqueleto::ABuiilderHordaEsqueleto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Ubicacion_Inicial = FVector(-3994.488813, -3997.341838, 0.0f);//Primera Posicion del Enemigo final
}

// Called when the game starts or when spawned
void ABuiilderHordaEsqueleto::BeginPlay()
{
	Super::BeginPlay();
	Horda = GetWorld()->SpawnActor<AHordaEnemigos>(AHordaEnemigos::StaticClass()); //Se instancia La Horda
	Laberinto = GetWorld()->SpawnActor<ALaberintoTerminado>(ALaberintoTerminado::StaticClass());
}


// Called every frame
void ABuiilderHordaEsqueleto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABuiilderHordaEsqueleto::ContruirEnemigoPeon(int cantidad)
{
	for (int i = 0; i < Laberinto->MapaLaberinto7.Num(); i++) {
		for (int j = 0; j < Laberinto->MapaLaberinto7[i].Num(); j++) {   
			int valor = Laberinto->MapaLaberinto7[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f)+FVector(200.0f,200.0f,0.0f);
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
		GetWorld()->SpawnActor<AEnemigo_EsqueletoPeon>(AEnemigo_EsqueletoPeon::StaticClass(),PosicionLibre[i],FRotator::ZeroRotator);
	}

}
void ABuiilderHordaEsqueleto::ContruirJefe(int cantidad)
{
	MezclarPosicion();

	
	int MaxSpawn = FMath::Min(cantidad, PosicionLibre.Num());
	for (int i = 0; i < MaxSpawn; i++) {
		GetWorld()->SpawnActor<AEnemigo_EsqueletoFinal>(AEnemigo_EsqueletoFinal::StaticClass(), PosicionLibre[i], FRotator::ZeroRotator);
	}
}


void ABuiilderHordaEsqueleto::ConstruirEnemigoMagico(int cantidad)
{
	MezclarPosicion();

	int MaxSpawn = FMath::Min(cantidad, PosicionLibre.Num());
	for (int i = 0; i < MaxSpawn; i++) {
		GetWorld()->SpawnActor<AEnemigo_EsqueletoMago>(AEnemigo_EsqueletoMago::StaticClass(), PosicionLibre[i], FRotator::ZeroRotator);
	}

}

void ABuiilderHordaEsqueleto::MezclarPosicion()
{
	for (int i = 0; i < PosicionLibre.Num(); i++) {
		int RandIndex = FMath::RandRange(i, PosicionLibre.Num() - 1);
		PosicionLibre.Swap(i, RandIndex);
	}
}

AHordaEnemigos* ABuiilderHordaEsqueleto::GetHorda()
{
	return Horda;		// Un Get hacia nuestro ObjetoAbstracto
}


