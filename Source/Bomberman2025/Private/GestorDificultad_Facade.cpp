// Fill out your copyright notice in the Description page of Project Settings.


#include "GestorDificultad_Facade.h"
#include "GestorNivelFAcil.h"
#include "GestorNivelMedio.h"
#include "GestorNivelDificil.h"

// Sets default values
AGestorDificultad_Facade::AGestorDificultad_Facade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGestorDificultad_Facade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGestorDificultad_Facade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGestorDificultad_Facade::ConfigurarNivel(int Dificultad)
{
	if (GestorActual)
	{
		GestorActual->Destroy();
		GestorActual = nullptr;
	}
	switch (Dificultad)
	{
	case 1: GestorActual = GetWorld()->SpawnActor<AGestorNivelFAcil>();
		break;
	case 2:
		GestorActual = GetWorld()->SpawnActor<AGestorNivelMedio>();
		break;
	case 3:
		GestorActual = GetWorld()->SpawnActor<AGestorNivelDificil>();

		break;
	default:
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Emerald, TEXT("No se inicio ningun nivel"));
		break;
	}
}


