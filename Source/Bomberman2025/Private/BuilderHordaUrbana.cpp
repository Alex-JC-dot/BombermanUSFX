#include "BuilderHordaUrbana.h"
#include "Enemigo_EsqueletoMago.h"


ABuilderHordaUrbana::ABuilderHordaUrbana()
{
	PrimaryActorTick.bCanEverTick = true;
	Ubicacion_Inicial = FVector(-3994.488813, -3997.341838, 0.0f);

}

void ABuilderHordaUrbana::BeginPlay()
{
	Super::BeginPlay();
	Horda = GetWorld()->SpawnActor<AHordaEnemigos>(AHordaEnemigos::StaticClass());
	Laberinto = GetWorld()->SpawnActor<ALaberintoTerminado>(ALaberintoTerminado::StaticClass());

}

void ABuilderHordaUrbana::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABuilderHordaUrbana::ContruirJefe(int cantidad)
{
	for (int i = 0; i < Laberinto->MapaLaberinto.Num(); i++) {
		for (int j = 0; j < Laberinto->MapaLaberinto[i].Num(); j++) {
			int valor = Laberinto->MapaLaberinto[i][j];
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
	for (int i = 0; i < MaxSpawn*2; i++) {
		GetWorld()->SpawnActor<AEnemigo_EsqueletoMago>(AEnemigo_EsqueletoMago::StaticClass(), PosicionLibre[i], FRotator::ZeroRotator);
	}

}

void ABuilderHordaUrbana::ContruirEnemigoPeon(int cantidad)
{
	MezclarPosicion();



}

void ABuilderHordaUrbana::ConstruirEnemigoMagico(int cantidad)
{


}
void ABuilderHordaUrbana::MezclarPosicion()
{
	for (int i = 0; i < PosicionLibre.Num(); i++) {
		int RandIndex = FMath::RandRange(i, PosicionLibre.Num() - 1);
		PosicionLibre.Swap(i, RandIndex);
	}

}
AHordaEnemigos* ABuilderHordaUrbana::GetHorda()
{

	return Horda;
}