// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderLava.h"
#include "Bloque_Cuarzo.h"
#include "Bloque_Roca.h"
#include "Puerta.h"
#include "PuertaNiveles_PuertaLava.h"
#include "PowerUpExplosion.h"
#include "PowerUpVelocidad.h"


// Sets default values
ABuilderLava::ABuilderLava()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Ubicacion_Inicial = FVector(-3994.488813, -3997.341838, 0.0f);
	ClasePuertaSiguiente = APuertaNiveles_PuertaLava::StaticClass();
}


// Called when the game starts or when spawned
void ABuilderLava::BeginPlay()
{
	Super::BeginPlay();
	Laberinto = GetWorld()->SpawnActor<ALaberintoTerminado>(ALaberintoTerminado::StaticClass());
}

// Called every frame
void ABuilderLava::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderLava::ConstruirBloqueFijo()
{
	ABloque* Bloque = nullptr;
	for (int32 i = 0; i < Laberinto->MapaLaberinto3.Num(); i++) {
		for (int32 j = 0; j < Laberinto->MapaLaberinto3[i].Num(); j++) {
			int32 valor = Laberinto->MapaLaberinto3[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 1) {
				Bloque = GetWorld()->SpawnActor<ABloque_Cuarzo>(ABloque_Cuarzo::StaticClass(), Posicion_Actual, FRotator::ZeroRotator); 			
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

void ABuilderLava::ConstruirBloqueDestructible()
{
	ABloque* Bloque = nullptr;
	for (int32 i = 0; i < Laberinto->MapaLaberinto3.Num(); i++) {
		for (int32 j = 0; j < Laberinto->MapaLaberinto3[i].Num(); j++) {
			int32 valor = Laberinto->MapaLaberinto3[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 2) { 
				Bloque = GetWorld()->SpawnActor<ABloque_Roca>(ABloque_Roca::StaticClass(), Posicion_Actual, FRotator::ZeroRotator);
				if (Bloque) {
					Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 3.0f));
					Laberinto->ElementosDelBuilder.Add(Bloque);
				}
			}
		
		}

	}

}

void ABuilderLava::ConstruirEntorno(int cantidad)
{
	for (int i = 0; i < cantidad; i++) {

		ElementoLava=GetWorld()->SpawnActor<AElementosLava>(AElementosLava::StaticClass(), PosicionEntorno[i]);
		UStaticMesh* Malla = AElementosLava::MEshRuta(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Lava/MountanasLava/scene.scene'"));
		ElementoLava->EstablecerMalla(Malla);
		Laberinto->ElementosDelBuilder.Add(ElementoLava);
	}
}

void ABuilderLava::ConstruirDecoracion(int cantidad)
{
	for (int32 i = 0; i < Laberinto->MapaLaberinto3.Num(); i++) {
		for (int32 j = 0; j < Laberinto->MapaLaberinto3[i].Num(); j++) {
			int32 valor = Laberinto->MapaLaberinto3[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 3) { 
			ElementoLava = GetWorld()->SpawnActor<AElementosLava>(AElementosLava::StaticClass(), Posicion_Actual, FRotator::ZeroRotator); 
				if (ElementoLava) {
				UStaticMesh* Malla = AElementosLava::MEshRuta(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Lava/Rocas/Roca.Roca'"));
				ElementoLava->EstablecerMalla(Malla);
				ElementoLava->SetActorScale3D(FVector(0.15f, 0.15f, 0.15f));
				Laberinto->ElementosDelBuilder.Add(ElementoLava);
				}
			}
		
		}

	}
}

void ABuilderLava::ConstruirPuerta(int cantidad)
{
	for (int32 i = 0; i < Laberinto->MapaLaberinto3.Num(); i++) {
		for (int32 j = 0; j < Laberinto->MapaLaberinto3[i].Num(); j++) {
			int32 valor = Laberinto->MapaLaberinto3[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 5) {
				auto puerta=GetWorld()->SpawnActor<APuerta>(APuerta::StaticClass(), Posicion_Actual + FVector(200.0f, 200.0f, 0.0f), FRotator::ZeroRotator); 
				Laberinto->ElementosDelBuilder.Add(puerta);
			}
		}

	}
}
ALaberintoTerminado* ABuilderLava::GetLaberinto()
{
	return Laberinto;
}

TSubclassOf<AActor> ABuilderLava::ObtenerClasePuerta()
{
	return ClasePuertaSiguiente;
}


