// Fill out your copyright notice in the Description page of Project Settings.


#include "BuiilderHordaEsqueleto.h"
#include "Enemigo_EsqueletoFinal.h"
#include "Enemigo_EsqueletoFinal.h"
#include "Enemigo_EsqueletoMago.h"
#include "Enemigo_EsqueletoPeon.h"

// Sets default values
ABuiilderHordaEsqueleto::ABuiilderHordaEsqueleto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Ubicacion_Inicial = FVector(1030.0, -1300.0, 0.0f);
}

// Called when the game starts or when spawned
void ABuiilderHordaEsqueleto::BeginPlay()
{
	Super::BeginPlay();
	Horda = GetWorld()->SpawnActor<AHordaEnemigos>(AHordaEnemigos::StaticClass());
}


// Called every frame
void ABuiilderHordaEsqueleto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuiilderHordaEsqueleto::ContruirJefe(int cantidad)
{	
	FVector Ubicacion(730.0f, -650.0f, 0.0f);
	for (int i = 0; i < cantidad; i++) {
		GetWorld()->SpawnActor<AEnemigo_EsqueletoFinal>(AEnemigo_EsqueletoFinal::StaticClass(), Ubicacion+(FVector(0.0f,300.0f,0.0f)*i), FRotator::ZeroRotator);
	}
}

void ABuiilderHordaEsqueleto::ContruirEnemigoPeon(int cantidad)
{
	for (int i = 0; i < Horda->PosicionPeon.Num(); i++) {
		for (int j = 0; j < Horda->PosicionPeon[i].Num(); j++) {
			int valor = Horda->PosicionPeon[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 1) {
				GetWorld()->SpawnActor<AEnemigo_EsqueletoPeon>(AEnemigo_EsqueletoPeon::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
			}
		}

	}

}

void ABuiilderHordaEsqueleto::ConstruirEnemigoMagico(int cantidad)
{
	for (int i = 0; i < Horda->PosicionPeon.Num(); i++) {
		for (int j = 0; j < Horda->PosicionPeon[i].Num(); j++) 
		{
			int valor = Horda->PosicionPeon[i][j];

			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 300.0f, j * 300.0f, 0.0f);
			if (valor == 2) 
			{
				GetWorld()->SpawnActor<AEnemigo_EsqueletoMago>(AEnemigo_EsqueletoMago::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
			}
		}
	}

}

AHordaEnemigos* ABuiilderHordaEsqueleto::GetHorda()
{
	return Horda;
}

