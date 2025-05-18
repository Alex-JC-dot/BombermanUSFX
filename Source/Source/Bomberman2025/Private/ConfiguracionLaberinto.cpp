// Fill out your copyright notice in the Description page of Project Settings.


#include "ConfiguracionLaberinto.h"

// Sets default values
AConfiguracionLaberinto::AConfiguracionLaberinto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConfiguracionLaberinto::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConfiguracionLaberinto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConfiguracionLaberinto::SetBloque(FString _Bloque)
{
	if (Builder) {
		Builder->ConstruirBloque();
	}


}

void AConfiguracionLaberinto::SetGrada(FString _Bloque)
{
	if (Builder) {
		Builder->ConstruirGrada(CantidadGrada);
	}
}

void AConfiguracionLaberinto::SetRefugio(FString _Bloque)
{
	if (Builder) {
		Builder->ConstruirRefugio(CantidadRefugio);
	}

}

void AConfiguracionLaberinto::SetPuerta(FString _Bloque)
{
	if (Builder) {
		Builder->ConstruirPuerta(CantidadPuerta);
	}
}
