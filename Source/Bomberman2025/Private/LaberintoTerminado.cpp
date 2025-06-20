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



void ALaberintoTerminado::SetBloqueFijo(FString _BloqueFijo)
{
	BloqueFijo = _BloqueFijo;
	if (GEngine) {
		FString Mensaje = FString::Printf(TEXT("Se Construyo: %s"), *BloqueFijo);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, Mensaje);
	}
}
void ALaberintoTerminado::SetBloqueDestructible(FString _BloqueDestructible)
{
	BloqueDestructible = _BloqueDestructible;

	if (GEngine) {
		FString Mensaje = FString::Printf(TEXT("Se Construyo: %s"), *BloqueDestructible);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, Mensaje);
	}
}

void ALaberintoTerminado::SetEntorno(FString _Entorno)
{
	Entorno = _Entorno;
	if (GEngine) {
		FString Mensaje = FString::Printf(TEXT("Se Construyo: %s"), *Entorno);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, Mensaje);
	}
}

void ALaberintoTerminado::SetDecoracion(FString _Decoracion)
{
	Decoracion = _Decoracion;
	if (GEngine) {
		FString Mensaje = FString::Printf(TEXT("Se Construyo: %s"), *Decoracion);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, Mensaje);
	}
}

void ALaberintoTerminado::SetPuerta(FString _Puerta)
{
	Puerta = _Puerta;
	if (GEngine) {
		FString Mensaje = FString::Printf(TEXT("Se Construyo: %s"), *Puerta);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Emerald, Mensaje);
	}
}


