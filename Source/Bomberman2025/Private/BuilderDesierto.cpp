// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderDesierto.h"
#include "Bloque_Arena.h"
#include "PuertaNiveles_PuertaDesierto.h"
#include "Bloque_ArenaFuerte.h"
#include "Puerta.h"

// Sets default values
ABuilderDesierto::ABuilderDesierto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Ubicacion_Inicial = FVector(-3994.488813, -3997.341838, 0.0f);
	ClasePuertaSiguiente = APuertaNiveles_PuertaDesierto::StaticClass();
}

// Called when the game starts or when spawned
void ABuilderDesierto::BeginPlay()
{
	Super::BeginPlay();
	Laberinto =GetWorld()->SpawnActor<ALaberintoTerminado>(ALaberintoTerminado::StaticClass());

}

// Called every frame
void ABuilderDesierto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderDesierto::ConstruirBloqueFijo()
{
	ABloque* Bloque = nullptr;
	for (int i = 0; i < Laberinto->MapaLaberinto5.Num(); i++) {
		for (int j = 0; j < Laberinto->MapaLaberinto5[i].Num(); j++) {
			int valor = Laberinto->MapaLaberinto5[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 1) { 
				Bloque = GetWorld()->SpawnActor<ABloque_ArenaFuerte>(ABloque_ArenaFuerte::StaticClass(), Posicion_Actual, FRotator::ZeroRotator); 
				if (Bloque) {
					Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 3.0f));
					Laberinto->ElementosDelBuilder.Add(Bloque);
				}
			}
		}
	}
}

void ABuilderDesierto::ConstruirBloqueDestructible()
{
	ABloque* Bloque = nullptr;
	for (int i = 0; i < Laberinto->MapaLaberinto5.Num(); i++) {
		for (int j = 0; j < Laberinto->MapaLaberinto5[i].Num(); j++) {
			int valor = Laberinto->MapaLaberinto5[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 2) { 
				Bloque = GetWorld()->SpawnActor<ABloque_Arena>(ABloque_Arena::StaticClass(), Posicion_Actual, FRotator::ZeroRotator); 
				if (Bloque) {
					Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 3.0f));
					Laberinto->ElementosDelBuilder.Add(Bloque);
				}
			}
		}
	}
}

void ABuilderDesierto::ConstruirEntorno(int cantidad)
{
	for (int i = 0; i < cantidad; i++) {

		ElementoDesierto = GetWorld()->SpawnActor<AElementosDesierto>(AElementosDesierto::StaticClass(), PosicionDesierto1[i]);
		UStaticMesh* MallaDesierto1 = AElementosDesierto::MeshRuta(ElementoDesierto->RutaDesierto1);
		ElementoDesierto->EstablecerMalla(MallaDesierto1);
		Laberinto->ElementosDelBuilder.Add(ElementoDesierto);

		ElementoDesierto = GetWorld()->SpawnActor<AElementosDesierto>(AElementosDesierto::StaticClass(), PosicionDesierto2[i]);
		UStaticMesh* MallaDesierto2 = AElementosDesierto::MeshRuta(ElementoDesierto->RutaDesierto2);
		ElementoDesierto->EstablecerMalla(MallaDesierto2);
		Laberinto->ElementosDelBuilder.Add(ElementoDesierto);

		ElementoDesierto = GetWorld()->SpawnActor<AElementosDesierto>(AElementosDesierto::StaticClass(), PosicionDesierto3[i]);
		UStaticMesh* MallaDesierto3 = AElementosDesierto::MeshRuta(ElementoDesierto->RutaDesierto3);
		ElementoDesierto->EstablecerMalla(MallaDesierto3);
		Laberinto->ElementosDelBuilder.Add(ElementoDesierto);

	}
}

void ABuilderDesierto::ConstruirDecoracion(int cantidad)
{
	for (int i = 0; i < Laberinto->MapaLaberinto5.Num(); i++) {
		for (int j = 0; j < Laberinto->MapaLaberinto5[i].Num(); j++) {
			int valor = Laberinto->MapaLaberinto5[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 4) {
				ElementoDesierto = GetWorld()->SpawnActor<AElementosDesierto>(AElementosDesierto::StaticClass(), Posicion_Actual+FVector(40.0f, 40.0f, 40.0f), FRotator::ZeroRotator);
				UStaticMesh* MallaCactus = AElementosDesierto::MeshRuta(ElementoDesierto->RutaCactus);
				ElementoDesierto->EstablecerMalla(MallaCactus);
				Laberinto->ElementosDelBuilder.Add(ElementoDesierto);
				if (ElementoDesierto) {
					ElementoDesierto->SetActorScale3D(FVector(0.004, 0.005, 0.008f));
				}
			}
		}
	}

}

void ABuilderDesierto::ConstruirPuerta(int cantidad)
{
	for (int32 i = 0; i < Laberinto->MapaLaberinto5.Num(); i++) {
		for (int32 j = 0; j < Laberinto->MapaLaberinto5[i].Num(); j++) {
			int32 valor = Laberinto->MapaLaberinto5[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 5) { 
				auto puerta=GetWorld()->SpawnActor<APuerta>(APuerta::StaticClass(), Posicion_Actual + FVector(200.0f, 200.0f, 0.0f), FRotator::ZeroRotator); 
				Laberinto->ElementosDelBuilder.Add(puerta);
		
			}
		}

	}
	Laberinto->SetEntorno("Puerta Desierto");

}

ALaberintoTerminado* ABuilderDesierto::GetLaberinto()
{

	return Laberinto;
}

TSubclassOf<AActor> ABuilderDesierto::ObtenerClasePuerta()
{
	return ClasePuertaSiguiente;
}

