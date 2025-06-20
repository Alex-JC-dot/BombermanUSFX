// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderHielo.h"
#include "Bloque_Hielo.h"
#include "Bloque_Concreto.h"
#include "Mountain.h"
#include "ManyMountains.h"
#include "Puerta.h"
#include "PuertaNiveles_PuertaHielo.h"
#include "PowerUpExplosion.h"
#include "PowerUpVelocidad.h"
#include "IceCluster.h"
#include "IceCulter2.h"
// Sets default values
ABuilderHielo::ABuilderHielo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Ubicacion_Inicial = FVector(-3994.488813, -3997.341838, 0.0f);
	ClasePuertaSiguiente = APuertaNiveles_PuertaHielo::StaticClass();
	
}

// Called when the game starts or when spawned
void ABuilderHielo::BeginPlay()
{
	Super::BeginPlay();
	Laberinto= GetWorld()->SpawnActor<ALaberintoTerminado>(ALaberintoTerminado::StaticClass());
}

// Called every frame
void ABuilderHielo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderHielo::ConstruirBloqueFijo()
{
	ABloque* Bloque = nullptr;
		for (int32 i = 0; i < Laberinto->MapaLaberinto2.Num(); i++) {
			for (int32 j = 0; j < Laberinto->MapaLaberinto2[i].Num(); j++) {
				int32 valor = Laberinto->MapaLaberinto2[i][j];
				FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
				if (valor == 1) { Bloque = GetWorld()->SpawnActor<ABloque_Hielo>(ABloque_Hielo::StaticClass(), Posicion_Actual, FRotator::ZeroRotator); }
				if (Bloque) {
					Laberinto->ElementosDelBuilder.Add(Bloque);
					Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 3.0f));
				
				}
				if (valor == 8) {
					PosicionSegura.Add(Posicion_Actual + FVector(200.0f, 200.0f, 0.0f));
				}
			}

		}

	
}

void ABuilderHielo::ConstruirBloqueDestructible()
{
	ABloque *Bloque = nullptr;
		for (int32 i = 0; i < Laberinto->MapaLaberinto2.Num(); i++) {
			for (int32 j = 0; j < Laberinto->MapaLaberinto2[i].Num(); j++) {
				int32 valor = Laberinto->MapaLaberinto2[i][j];
				FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
				if (valor == 2) { Bloque = GetWorld()->SpawnActor<ABloque_Concreto>(ABloque_Concreto::StaticClass(), Posicion_Actual, FRotator::ZeroRotator); }
				if (Bloque) {
					Laberinto->ElementosDelBuilder.Add(Bloque);
					Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 3.0f));
					PosicionPowerUps.Add(Posicion_Actual);
				}
			}
		

		}
		for (int i = 0; i < CantidadPowerUp; i++) {
			int IndiceAleatorio = FMath::RandRange(0, PosicionPowerUps.Num() - 1);
			FVector Pos = PosicionPowerUps[IndiceAleatorio] + FVector(200.0f, 200.0f, 80.0f);

			if (i % 2 == 0) {
				auto PowerExplosion = GetWorld()->SpawnActor<APowerUpExplosion>(APowerUpExplosion::StaticClass(), Pos, FRotator::ZeroRotator);
				Laberinto->ElementosDelBuilder.Add(PowerExplosion);
			}
			else {
				auto PowerVelocidad = GetWorld()->SpawnActor<APowerUpVelocidad>(APowerUpVelocidad::StaticClass(), Pos, FRotator::ZeroRotator);
				Laberinto->ElementosDelBuilder.Add(PowerVelocidad);
			}

			PosicionPowerUps.RemoveAt(IndiceAleatorio);

		}
	

}

void ABuilderHielo::ConstruirEntorno(int cantidad)
{
	for (int i = 0; i < cantidad; i++) {

		auto Montanas =GetWorld()->SpawnActor<AManyMountains>(AManyMountains::StaticClass(), PosicionMuchasMontanas[i]);
		if (Montanas) 
		{ 
			Laberinto->ElementosDelBuilder.Add(Montanas);
		}
		auto Montana =GetWorld()->SpawnActor<AMountain>(AMountain::StaticClass(), PosicionMontanas[i]);
		if (Montana)
		{
			Laberinto->ElementosDelBuilder.Add(Montana);
		}
	}
}

void ABuilderHielo::ConstruirDecoracion(int cantidad)
{
	for (int32 i = 0; i < Laberinto->MapaLaberinto2.Num(); i++) {
		for (int32 j = 0; j < Laberinto->MapaLaberinto2[i].Num(); j++) {
			int32 valor = Laberinto->MapaLaberinto2[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 3) { 
				auto Decoracion=GetWorld()->SpawnActor<AIceCluster>(AIceCluster::StaticClass(), Posicion_Actual +FVector(50.0f, 50.0f, 0.0f), FRotator::ZeroRotator); 
				Laberinto->ElementosDelBuilder.Add(Decoracion);
			}
			if (valor == 4) { 
				auto Decoracion = GetWorld()->SpawnActor<AIceCulter2>(AIceCulter2::StaticClass(), Posicion_Actual + FVector(50.0f, 50.0f, 80.0f), FRotator::ZeroRotator);
				Laberinto->ElementosDelBuilder.Add(Decoracion);
			}
		}


	}
}

void ABuilderHielo::ConstruirPuerta(int cantidad)
{
	for (int32 i = 0; i < Laberinto->MapaLaberinto2.Num(); i++) {
		for (int32 j = 0; j < Laberinto->MapaLaberinto2[i].Num(); j++) {
			int32 valor = Laberinto->MapaLaberinto2[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 5) {  
				auto puerta= GetWorld()->SpawnActor<APuerta>(APuerta::StaticClass(), Posicion_Actual +FVector(200.0f, 200.0f, 0.0f), FRotator::ZeroRotator);
				if (puerta) {
					Laberinto->ElementosDelBuilder.Add(puerta);
				
				}

			}
		}
		

	}
}

ALaberintoTerminado* ABuilderHielo::GetLaberinto()
{


	return Laberinto;
}

TSubclassOf<AActor> ABuilderHielo::ObtenerClasePuerta()
{
	return ClasePuertaSiguiente;
}

