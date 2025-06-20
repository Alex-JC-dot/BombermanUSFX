// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderCementerio.h"
#include "Bloque_Cemento.h"
#include "Bloque_Piedra.h"
#include "Puerta.h"
#include "PuertaNiveles_PuertaCementerio.h"
#include "PowerUpExplosion.h"
#include "PowerUpVelocidad.h"


// Sets default values
ABuilderCementerio::ABuilderCementerio()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Ubicacion_Inicial = FVector(-3994.488813, -3997.341838, 0.0f);
	ClasePuertaSiguiente = APuertaNiveles_PuertaCementerio::StaticClass();
}

// Called when the game starts or when spawned
void ABuilderCementerio::BeginPlay()
{
	Super::BeginPlay();
	Laberinto =GetWorld()->SpawnActor<ALaberintoTerminado>(ALaberintoTerminado::StaticClass());

}

// Called every frame
void ABuilderCementerio::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderCementerio::ConstruirBloqueFijo()
{
	ABloque* Bloque = nullptr;
	for (int i = 0; i < Laberinto->MapaLaberinto6.Num(); i++) {
		for (int j = 0; j < Laberinto->MapaLaberinto6[i].Num(); j++) {
			int valor = Laberinto->MapaLaberinto6[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 1) { 
				Bloque = GetWorld()->SpawnActor<ABloque_Piedra>(ABloque_Piedra::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);		
			}
			
			if (Bloque) {
				Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 3.0f));
				Laberinto->ElementosDelBuilder.Add(Bloque);
				
			}
		}
	}

}

void ABuilderCementerio::ConstruirBloqueDestructible()
{
	ABloque* Bloque = nullptr;
	for (int i = 0; i < Laberinto->MapaLaberinto6.Num(); i++) {
		for (int j = 0; j < Laberinto->MapaLaberinto6[i].Num(); j++) {
			int valor = Laberinto->MapaLaberinto6[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 2) {
				Bloque = GetWorld()->SpawnActor<ABloque_Cemento>(ABloque_Cemento::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
				Laberinto->ElementosDelBuilder.Add(Bloque);

				if (Bloque) {

					Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 3.0f));
					Laberinto->ElementosDelBuilder.Add(Bloque);
					PosicionPowerUps.Add(Posicion_Actual);
				}
			}
		}
	}
	/*for (int i = 0; i < CantidadPowerUp; i++) {
		int IndiceAleatorio = FMath::RandRange(0, PosicionPowerUps.Num() - 1);
		FVector Pos = PosicionPowerUps[IndiceAleatorio] + FVector(200.0f, 200.0f, 80.0f);

		if (i % 2 == 0) {
			auto PowerExplosion = GetWorld()->SpawnActor<APowerUpExplosion>(APowerUpExplosion::StaticClass(), Pos, FRotator::ZeroRotator);
			Laberinto->ElementosDelBuilder.Add(PowerExplosion);


		}
		else {
			auto PowerVelocidad=GetWorld()->SpawnActor<APowerUpVelocidad>(APowerUpVelocidad::StaticClass(), Pos, FRotator::ZeroRotator);
			Laberinto->ElementosDelBuilder.Add(PowerVelocidad);

		}

		PosicionPowerUps.RemoveAt(IndiceAleatorio);

	}*/
}

void ABuilderCementerio::ConstruirEntorno(int cantidad)
{
	for (int i = 0; i < cantidad; i++) {
		ElementosCementerio = GetWorld()->SpawnActor<AElementosCementerio>(AElementosCementerio::StaticClass(), PosicionLapida[i]);
		UStaticMesh* MallaCementerio = AElementosCementerio::MeshRuta(ElementosCementerio->RutaLapida1);
		ElementosCementerio->EstablecerMalla(MallaCementerio);
		Laberinto->ElementosDelBuilder.Add(ElementosCementerio);

		ElementosCementerio = GetWorld()->SpawnActor<AElementosCementerio>(AElementosCementerio::StaticClass(), PosicionIglesia[i]);
		UStaticMesh* MallaIglesia = AElementosCementerio::MeshRuta(ElementosCementerio->RutaIglesia);
		ElementosCementerio->EstablecerMalla(MallaIglesia);
		Laberinto->ElementosDelBuilder.Add(ElementosCementerio);
	}

}

void ABuilderCementerio::ConstruirDecoracion(int cantidad)
{
	for (int i = 0; i < Laberinto->MapaLaberinto6.Num(); i++) {
		for (int j = 0; j < Laberinto->MapaLaberinto6[i].Num(); j++) {
			int valor = Laberinto->MapaLaberinto6[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			int RotacionAleatoria = FMath::RandRange(0, 3);
			if (valor == 3) {
				ElementosCementerio = GetWorld()->SpawnActor<AElementosCementerio>(AElementosCementerio::StaticClass(), Posicion_Actual + FVector(70.0f, 70.0f, 11.0f), FRotator(0.0f, 90.0f, 0.0f) * RotacionAleatoria);
				UStaticMesh* MallaCalavera = AElementosCementerio::MeshRuta(ElementosCementerio->RutaCalavera);
				ElementosCementerio->EstablecerMalla(MallaCalavera);
				if (ElementosCementerio) {
					ElementosCementerio->SetActorScale3D(FVector(0.002, 0.002, 0.002));
					Laberinto->ElementosDelBuilder.Add(ElementosCementerio);
				}
				if (UStaticMeshComponent* ComponenteMalla = ElementosCementerio->FindComponentByClass<UStaticMeshComponent>()) {
					ComponenteMalla->SetCollisionEnabled(ECollisionEnabled::NoCollision);
					ComponenteMalla->SetGenerateOverlapEvents(false); 
				}				
			}
			if (valor == 4) {
				ElementosCementerio = GetWorld()->SpawnActor<AElementosCementerio>(AElementosCementerio::StaticClass(), Posicion_Actual + FVector(180.0f, 180.0f, 100.0f), FRotator::ZeroRotator);
				UStaticMesh* MallaTumba = AElementosCementerio::MeshRuta(ElementosCementerio->RutaTumba);
				ElementosCementerio->EstablecerMalla(MallaTumba);
				Laberinto->ElementosDelBuilder.Add(ElementosCementerio);
			}
		}
	}
}

void ABuilderCementerio::ConstruirPuerta(int cantidad)
{
	for (int32 i = 0; i < Laberinto->MapaLaberinto6.Num(); i++) {
		for (int32 j = 0; j < Laberinto->MapaLaberinto6[i].Num(); j++) {
			int32 valor = Laberinto->MapaLaberinto6[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 5) {
				auto puerta = GetWorld()->SpawnActor<APuerta>(APuerta::StaticClass(), Posicion_Actual + FVector(200.0f, 200.0f, 0.0f), FRotator::ZeroRotator);
				if (puerta) {
					Laberinto->ElementosDelBuilder.Add(puerta);

				}
			}
		}

	}
	Laberinto->SetEntorno("Puerta Cementerio");

}

ALaberintoTerminado* ABuilderCementerio::GetLaberinto()
{
	return Laberinto;
}

TSubclassOf<AActor> ABuilderCementerio::ObtenerClasePuerta()
{
	return ClasePuertaSiguiente;
}


