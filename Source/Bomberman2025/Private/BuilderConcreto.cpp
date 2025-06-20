// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderConcreto.h"
#include "PuertaNiveles_PuertaUrabano.h"
#include "LaberintoTerminado.h"
#include "Bloque_Ladrillo.h"
#include "Bloque_Pasto.h"
#include "Bloque.h"
#include "Puerta.h"
#include "Planta.h"
#include "Hidrante.h"
#include "Contenedor.h"
#include "Edificio2.h"
#include "Edificio1.h"
#include "PowerUpExplosion.h"
#include "PowerUpVelocidad.h"

// Sets default values
ABuilderConcreto::ABuilderConcreto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UbicacionInicial = FVector(-3994.488813, -3997.341838, 0.0f);
	ClasePuertaSiguiente = APuertaNiveles_PuertaUrabano::StaticClass();

}

// Called when the game starts or when spawned
void ABuilderConcreto::BeginPlay()
{
	Super::BeginPlay();
	Laberinto = GetWorld()->SpawnActor<ALaberintoTerminado>(ALaberintoTerminado::StaticClass());
}

// Called every frame
void ABuilderConcreto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderConcreto::ConstruirBloqueFijo()
{
	ABloque* Bloque=nullptr;
	for (int fila = 0; fila < Laberinto->MapaLaberinto.Num(); fila++) {
		for (int columna = 0; columna < Laberinto->MapaLaberinto[fila].Num(); columna++) {
			int valor = Laberinto->MapaLaberinto[fila][columna];
			FVector Posicion_Actual = UbicacionInicial + FVector(fila * 400.0f, columna * 400.0f, 0.0f);
			if (valor == 1) {
				Bloque = GetWorld()->SpawnActor<ABloque_Ladrillo>(ABloque_Ladrillo::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
				if (Bloque) {
					Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 3.0f));
					Laberinto->ElementosDelBuilder.Add(Bloque);
				}
			}
		}
	}
	Laberinto->SetBloqueFijo("Bloque Ladrillo");

}

void ABuilderConcreto::ConstruirBloqueDestructible()
{
	ABloque* Bloque = nullptr;
	for (int fila = 0; fila < Laberinto->MapaLaberinto.Num(); fila++)
	{
		for (int columna = 0; columna < Laberinto->MapaLaberinto[fila].Num(); columna++) {
			int valor = Laberinto->MapaLaberinto[fila][columna];
			FVector Posicion_Actual = UbicacionInicial + FVector(fila * 400.0f, columna * 400.0f, 0.0f);
			if (valor == 2) {
				Bloque = GetWorld()->SpawnActor<ABloque_Pasto>(ABloque_Pasto::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
			
				if (Bloque) {
					Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 3.0f));
					Laberinto->ElementosDelBuilder.Add(Bloque);
					PosicionPowerUps.Add(Posicion_Actual);
				}
			}
		}
	}
	Laberinto->SetBloqueDestructible("Bloques de pasto");


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

void ABuilderConcreto::ConstruirEntorno(int cantidad)
{

	for (int i = 0; i < cantidad; i++) {
	auto Vecindario=GetWorld()->SpawnActor<AEdificio2>(AEdificio2::StaticClass(), Vecindarios[i] );
	Laberinto->ElementosDelBuilder.Add(Vecindario);
	auto Edificio=	GetWorld()->SpawnActor<AEdificio1>(AEdificio1::StaticClass(), Edificios[i]);
	Laberinto->ElementosDelBuilder.Add(Edificio);
	}
	Laberinto->SetEntorno("Contorno Urbano");
}

void ABuilderConcreto::ConstruirDecoracion(int cantidad)
{
	//ABloque* Bloque = nullptr;
	for (int fila = 0; fila < Laberinto->MapaLaberinto.Num(); fila++) {
		for (int columna = 0; columna < Laberinto->MapaLaberinto[fila].Num(); columna++) {
			int valor = Laberinto->MapaLaberinto[fila][columna];
			FVector Posicion_Actual = UbicacionInicial + FVector(fila * 400.0f, columna * 400.0f, 0.0f);
			if (valor == 3) {
				auto contenedor= GetWorld()->SpawnActor<AContenedor>(AContenedor::StaticClass(), Posicion_Actual+FVector(100.0f,100.0f,0.0f), FRotator::ZeroRotator);
				 Laberinto->ElementosDelBuilder.Add(contenedor);
			}
			if (valor == 4) {
				 auto Hidrante = GetWorld()->SpawnActor<AHidrante>(AHidrante::StaticClass(), Posicion_Actual + FVector(100.0f, 100.0f, 0.0f), FRotator::ZeroRotator);
				 Laberinto->ElementosDelBuilder.Add(Hidrante);
			}
			if (valor == 5) {
				auto contenedor = GetWorld()->SpawnActor<AContenedor>(AContenedor::StaticClass(), Posicion_Actual + FVector(250.0f, 150.0f, 0.0f), FRotator(0.0f,180.0f,0.0f));
				
			}
		}
	}
	Laberinto->SetDecoracion("Decoracion Urbana: Hidrante y Contenedores");
}

void ABuilderConcreto::ConstruirPuerta(int cantidad)
{
	FVector Posicion(3455.511187f, -3387.341797, 0.0f);
	FVector Posicion2(3455.511187f, -987.341858, 0.0f);
	FRotator Rotacion(0.0f, 270.0f, 0.0f);
	for (int i = 0; i < cantidad; i++) {
		if (i == 0) { auto puerta=GetWorld()->SpawnActor<APuerta>(APuerta::StaticClass(), Posicion, Rotacion); 
		Laberinto->ElementosDelBuilder.Add(puerta);
		
		}
		if (i == 1) { auto puerta=GetWorld()->SpawnActor<APuerta>(APuerta::StaticClass(), Posicion2, Rotacion);
		Laberinto->ElementosDelBuilder.Add(puerta);
		}
	}
	Laberinto->SetEntorno("Puerta Urbana");
}

ALaberintoTerminado* ABuilderConcreto::GetLaberinto()
{
	return Laberinto;
}

TSubclassOf<AActor> ABuilderConcreto::ObtenerClasePuerta()
{
	return ClasePuertaSiguiente;
}



