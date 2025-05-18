// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaBloqueMadera.h"
#include "Bloque_Madera.h"
#include "Enemigo_Subterraneo.h"
#include "ArbolJungla.h"
#include "Planta.h"
#include "Monumento.h"
// Sets default values
AFabricaBloqueMadera::AFabricaBloqueMadera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void AFabricaBloqueMadera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaBloqueMadera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
ABloque* AFabricaBloqueMadera::CrearBloqueMadera(FVector Pos)
{
	FVector Escala (4.0f, 4.0f, 5.0f);
	FTransform Transform(FRotator::ZeroRotator, Pos, Escala);
	return GetWorld()->SpawnActor<ABloque_Madera>(ABloque_Madera::StaticClass(), Transform);;
}

AEnemigo* AFabricaBloqueMadera::CrearEnemigoMadera(FVector Posicion)
{
	//FVector Tamano =FVector()
	FTransform Transform(FRotator::ZeroRotator, Posicion);
	return GetWorld()->SpawnActor<AEnemigo_Subterraneo>(AEnemigo_Subterraneo::StaticClass(), Transform);
	
}

AArbolJungla* AFabricaBloqueMadera::CrerarArbolMadera(FVector Posicion)
{
	FTransform Transform(FRotator::ZeroRotator, Posicion);
	return GetWorld()->SpawnActor<AArbolJungla>(AArbolJungla::StaticClass(), Transform);

}

APlanta* AFabricaBloqueMadera::CrearPlanta(FVector Posicion)
{
	FVector PosicionCentrada = Posicion + FVector(200.0f,200.0f,0.0f);
	FVector Escala(0.4f, 0.4f, 0.4f);
	FTransform Transform(FRotator::ZeroRotator, PosicionCentrada, Escala);
	return GetWorld()->SpawnActor<APlanta>(APlanta::StaticClass(), Transform);;

}

AMonumento* AFabricaBloqueMadera::CrearMonumento(FVector Posicion,FRotator Rotacion)
{
	FVector Escala(0.02f, 0.02f, 0.03f);
	FTransform Transform(Rotacion, Posicion, Escala);
	return GetWorld()->SpawnActor<AMonumento>(AMonumento::StaticClass(), Transform);;
}


