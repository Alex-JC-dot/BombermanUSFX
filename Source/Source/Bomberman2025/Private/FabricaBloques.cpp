// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaBloques.h"
#include "Bloque_Acero.h"
#include "Bloque_Madera.h"
#include"Bloque_Concreto.h"
#include"Bloque_Ladrillo.h"

// Sets default values
AFabricaBloques::AFabricaBloques()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFabricaBloques::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaBloques::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
ABloque *AFabricaBloques::CrearBloque(FString TipoBloque, FVector posicion)
{
	FVector Tamano (4.0f, 4.0f, 5.0f);
	FTransform Transform(FRotator::ZeroRotator, posicion, Tamano);
	//Select which potion to spawn depending on the passed string
	if (TipoBloque.Equals("Acero")) {
		return GetWorld()->SpawnActor<ABloque_Acero>
			(ABloque_Acero::StaticClass(), Transform);
	}
	else if (TipoBloque.Equals("Madera")) {
		return GetWorld()->SpawnActor<ABloque_Madera>
			(ABloque_Madera::StaticClass(), Transform );
	}
	else if (TipoBloque.Equals("Concreto")) {
		return GetWorld()->SpawnActor<ABloque_Concreto>
			(ABloque_Concreto::StaticClass(), Transform);
	}
	else if (TipoBloque.Equals("Ladrillo")) {
		return GetWorld()->SpawnActor<ABloque_Ladrillo>
			(ABloque_Ladrillo::StaticClass(), Transform);
	}
	else return nullptr; //Return null if the string isn't valid
}




