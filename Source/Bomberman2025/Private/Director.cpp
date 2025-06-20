// Fill out your copyright notice in the Description page of Project Settings.


#include "Director.h"
#include "LaberintoTerminado.h"

// Sets default values
ADirector::ADirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirector::LlamarConstructor(AActor* _Constructor)
{
	ConstructorEscenario = Cast<IIBuilderEscenario>(_Constructor);

}

void ADirector::ConstruirLaberinto()
{
	
	ConstructorEscenario->ConstruirBloqueFijo();
	ConstructorEscenario->ConstruirBloqueDestructible();
	ConstructorEscenario->ConstruirPuerta(ConstructorEscenario->GetCantidadPuertas());
	ConstructorEscenario->ConstruirEntorno(ConstructorEscenario->GetCantidadEntorno());
	ConstructorEscenario->ConstruirDecoracion(ConstructorEscenario->GetCantidadDecoracion());
	
	
}


ALaberintoTerminado* ADirector::GetLaberinto()
{
	if (ConstructorEscenario) 
	{
		return ConstructorEscenario->GetLaberinto();
	}
		return nullptr;
	
}



