#include "LaberintoTerminado.h"
// Fill out your copyright notice in the Description page of Project Settings.


// Sets default values
ALaberintoTerminado::ALaberintoTerminado()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALaberintoTerminado::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaberintoTerminado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaberintoTerminado::SetBloque(FString _Bloque)
{
	Bloque = _Bloque;
}

void ALaberintoTerminado::SetGrada(FString _Grada)
{
	Grada = _Grada;
}

void ALaberintoTerminado::SetRefugio(FString _Refugio)
{
	Refugio = _Refugio;
}

void ALaberintoTerminado::SetPuerta(FString _Puerta)
{
	Puerta = _Puerta;
}


