

#include "BuilderAntiguo.h"
#include "Bloque_Pasto.h"
#include "Bloque_Acero.h"
#include "PowerUpVelocidad.h"
#include "PowerUpExplosion.h" 
#include "ElementosAntiguo.h"
#include "PuertaNiveles_PuertaAntigua.h"
#include "PuertaNiveles_PuertaHielo.h"
#include "Puerta.h"

ABuilderAntiguo::ABuilderAntiguo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Ubicacion_Inicial = FVector(-3994.488813, -3997.341838, 0.0f);
	ClasePuertaSiguiente = APuertaNiveles_PuertaAntigua::StaticClass();
}

// Called when the game starts or when spawned
void ABuilderAntiguo::BeginPlay()
{
	Super::BeginPlay();
	Laberinto = GetWorld()->SpawnActor<ALaberintoTerminado>(ALaberintoTerminado::StaticClass());
}


// Called every frame
void ABuilderAntiguo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderAntiguo::ConstruirBloqueFijo()
{
	ABloque* Bloque = nullptr;
	for (int i = 0; i < Laberinto->MapaLaberinto7.Num(); i++) {
		for (int j = 0; j < Laberinto->MapaLaberinto7[i].Num(); j++) {
			int valor = Laberinto->MapaLaberinto7[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 1) { Bloque = GetWorld()->SpawnActor<ABloque_Acero>(ABloque_Acero::StaticClass(), Posicion_Actual, FRotator::ZeroRotator); }
			if (Bloque) {
				Bloque->SetActorScale3D(FVector(4.0f, 4.0f, 3.0f));
				Laberinto->ElementosDelBuilder.Add(Bloque);
			}
		}
	}


}

void ABuilderAntiguo::ConstruirBloqueDestructible()
{
	ABloque* Bloque = nullptr;
	for (int i = 0; i < Laberinto->MapaLaberinto7.Num(); i++) {
		for (int j = 0; j < Laberinto->MapaLaberinto7[i].Num(); j++) {
			int valor = Laberinto->MapaLaberinto7[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
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

void ABuilderAntiguo::ConstruirEntorno(int cantidad)
{
	for (int i = 0; i < cantidad; i++) {

		ElementoAntiguo = GetWorld()->SpawnActor<AElementosAntiguo>(AElementosAntiguo::StaticClass(), PosicionMonumento[i]);
		UStaticMesh* MallaMonumento = AElementosAntiguo::MeshRuta(ElementoAntiguo->RutaMonumento);
		ElementoAntiguo->EstablecerMalla(MallaMonumento);
		Laberinto->ElementosDelBuilder.Add(ElementoAntiguo);

		ElementoAntiguo = GetWorld()->SpawnActor<AElementosAntiguo>(AElementosAntiguo::StaticClass(), PosicionRuina[i]);
		UStaticMesh* MallaRuina = AElementosAntiguo::MeshRuta(ElementoAntiguo->RutaRuinas);
		ElementoAntiguo->EstablecerMalla(MallaRuina);
		Laberinto->ElementosDelBuilder.Add(ElementoAntiguo);
	}

	ElementoAntiguo = GetWorld()->SpawnActor<AElementosAntiguo>(AElementosAntiguo::StaticClass(), FVector(-9510.0, -430.0, -390.0), FRotator(0.0f, -90.0f, 0.0f));
	UStaticMesh* MallaRodas = AElementosAntiguo::MeshRuta(ElementoAntiguo->RutaRodas);
	ElementoAntiguo->EstablecerMalla(MallaRodas);
	Laberinto->ElementosDelBuilder.Add(ElementoAntiguo);

}

void ABuilderAntiguo::ConstruirDecoracion(int cantidad)
{
	
}

void ABuilderAntiguo::ConstruirPuerta(int cantidad)
{
	for (int i = 0; i < Laberinto->MapaLaberinto7.Num(); i++) {
		for (int j = 0; j < Laberinto->MapaLaberinto7[i].Num(); j++) {
			int valor = Laberinto->MapaLaberinto7[i][j];
			FVector Posicion_Actual = Ubicacion_Inicial + FVector(i * 400.0f, j * 400.0f, 0.0f);
			if (valor == 5)
			{
				auto puerta = GetWorld()->SpawnActor<APuerta>(APuerta::StaticClass(), Posicion_Actual + FVector(200.0f, 200.0f, 0.0f), FRotator::ZeroRotator);
				if (puerta) {
					Laberinto->ElementosDelBuilder.Add(puerta);
			
				}
			}
		}
	}
}

ALaberintoTerminado* ABuilderAntiguo::GetLaberinto()
{
	return Laberinto;
}

TSubclassOf<AActor> ABuilderAntiguo::ObtenerClasePuerta()
{
	return ClasePuertaSiguiente;
}


