// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderMedieval.h"
#include "Bloque_Caja.h"
#include "Bloque_Acero.h"
#include "Puerta.h"
#include "PuertaNiveles_PuertaCementerio.h"
#include "PowerUpExplosion.h"
#include "PowerUpVelocidad.h"


// Sets default values
ABuilderMedieval::ABuilderMedieval()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Ubicacion_Inicial = FVector(-3994.488813, -3997.341838, 0.0f);
	ClasePuertaSiguiente = APuertaNiveles_PuertaCementerio::StaticClass();
}

// Called when the game starts or when spawned
void ABuilderMedieval::BeginPlay()
{
	Super::BeginPlay();
	Laberinto = GetWorld()->SpawnActor<ALaberintoTerminado>(ALaberintoTerminado::StaticClass());

}

// Called every frame
void ABuilderMedieval::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderMedieval::ConstruirBloqueFijo()
{
	ABloque* Bloque = nullptr;
	for (int32 i = 0; i < Laberinto->MapaLaberinto4.Num(); i++) {
		for (int32 j = 0; j < Laberinto->MapaLaberinto4[i].Num(); j++) {
			int32 valor = Laberinto->MapaLaberinto4[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 1) {
				Bloque = GetWorld()->SpawnActor<ABloque_Acero>(ABloque_Acero::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
				if (Bloque) {
					Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 3.0f));
					Laberinto->ElementosDelBuilder.Add(Bloque);
				}
			}
		}

	}
}

void ABuilderMedieval::ConstruirBloqueDestructible()
{
	ABloque* Bloque = nullptr;
	for (int32 i = 0; i < Laberinto->MapaLaberinto4.Num(); i++) {
		for (int32 j = 0; j < Laberinto->MapaLaberinto4[i].Num(); j++) {
			int32 valor = Laberinto->MapaLaberinto4[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 2) { Bloque = GetWorld()->SpawnActor<ABloque_Caja>(ABloque_Caja::StaticClass(), Posicion_Actual, FRotator::ZeroRotator); 
				if (Bloque) {
					Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 3.0f));
					Laberinto->ElementosDelBuilder.Add(Bloque);
					PosicionPowerUps.Add(Posicion_Actual);

				}
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

void ABuilderMedieval::ConstruirEntorno(int cantidad)
{
	for (int i = 0; i < cantidad; i++) {

		ElementoMedieval = GetWorld()->SpawnActor<AElementosMedieval>(AElementosMedieval::StaticClass(), PosicionCasa[i]);
		UStaticMesh* MallaCasa = AElementosMedieval::MeshRuta(ElementoMedieval->RutaCasa);
		ElementoMedieval->EstablecerMalla(MallaCasa);
		Laberinto->ElementosDelBuilder.Add(ElementoMedieval);
	

		ElementoMedieval = GetWorld()->SpawnActor<AElementosMedieval>(AElementosMedieval::StaticClass(), PosicionLago[i]);
		UStaticMesh* MallaLago = AElementosMedieval::MeshRuta(ElementoMedieval->RutaLago);
		ElementoMedieval->EstablecerMalla(MallaLago);
		Laberinto->ElementosDelBuilder.Add(ElementoMedieval);
	}
	for (int i = 0; i < PosicionCaverna.Num(); i++) {
		ElementoMedieval = GetWorld()->SpawnActor<AElementosMedieval>(AElementosMedieval::StaticClass(), PosicionCaverna[i]);
		UStaticMesh* MallaCaverna = AElementosMedieval::MeshRuta(ElementoMedieval->RutaCaverna);
		ElementoMedieval->EstablecerMalla(MallaCaverna);
		Laberinto->ElementosDelBuilder.Add(ElementoMedieval);
	}
	ElementoMedieval = GetWorld()->SpawnActor<AElementosMedieval>(AElementosMedieval::StaticClass(), PosicionCastillo);
	UStaticMesh* Malla = AElementosMedieval::MeshRuta(ElementoMedieval->RutaCastillo);
	ElementoMedieval->EstablecerMalla(Malla);
	Laberinto->ElementosDelBuilder.Add(ElementoMedieval);
}
void ABuilderMedieval::ConstruirDecoracion(int Cantidad)
{
	for (int32 i = 0; i < Laberinto->MapaLaberinto4.Num(); i++) {
		for (int32 j = 0; j < Laberinto->MapaLaberinto4[i].Num(); j++) {
			int32 valor = Laberinto->MapaLaberinto4[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 4) {
				ElementoMedieval = GetWorld()->SpawnActor<AElementosMedieval>(AElementosMedieval::StaticClass(), Posicion_Actual + FVector(80.0f, 200.0f, 0.0f), FRotator::ZeroRotator);
				UStaticMesh* MallaMercado = AElementosMedieval::MeshRuta(ElementoMedieval->RutaMercado);
				ElementoMedieval->EstablecerMalla(MallaMercado);
				if (ElementoMedieval) {
					ElementoMedieval->SetActorScale3D(FVector(1.0, 1.0, 1.4f));
					Laberinto->ElementosDelBuilder.Add(ElementoMedieval);

				}
			}
		}

	}
}

void ABuilderMedieval::ConstruirPuerta(int cantidad)
{
	for (int32 i = 0; i < Laberinto->MapaLaberinto4.Num(); i++) {
		for (int32 j = 0; j < Laberinto->MapaLaberinto4[i].Num(); j++) {
			int32 valor = Laberinto->MapaLaberinto4[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 5) { 
			auto puerta=GetWorld()->SpawnActor<APuerta>(APuerta::StaticClass(), Posicion_Actual + FVector(200.0f, 200.0f, 0.0f), FRotator::ZeroRotator); 
			
			Laberinto->ElementosDelBuilder.Add(puerta);
			}
		}

	}
	Laberinto->SetEntorno("Puerta Medieval");
}

ALaberintoTerminado* ABuilderMedieval::GetLaberinto()
{
	return Laberinto;
}

TSubclassOf<AActor> ABuilderMedieval::ObtenerClasePuerta()
{
	return ClasePuertaSiguiente;
}

