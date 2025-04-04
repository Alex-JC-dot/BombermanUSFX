// Copyright Epic Games, Inc. All Rights Reserved.
// Copyright Epic Games, Inc. All Rights Reserved.

#include "Bomberman2025GameMode.h"
#include "Bomberman2025Character.h"
#include  "Piso.h"
#include  "Ladrillo.h"
#include "Ladrillo2.h"
#include "UObject/ConstructorHelpers.h"

ABomberman2025GameMode::ABomberman2025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
void ABomberman2025GameMode::BeginPlay()
{
	//Ladrillo1 (movimiento)
	Super::BeginPlay();
	FVector Ubicacion = FVector(0.0f, 0.0f, 30.0f);
	FRotator Rotacion = FRotator::ZeroRotator;
	if (GetWorld())
	{
		GetWorld()->SpawnActor<APiso>(APiso::StaticClass(), Ubicacion, Rotacion);
	}
	FVector UbicacionInicial = FVector(-3500.0f, 3700.0f, 20.0f);  // Primera posición del bloque
	float DistanciaEntreBloques = 400.0f;


	if (GetWorld())
	{
		for (int i = 0; i < 20; i++)
		{
			FVector PosicionActual = UbicacionInicial + FVector(i * DistanciaEntreBloques, 0.0f, 0.0f);
			GetWorld()->SpawnActor<ALadrillo>(ALadrillo::StaticClass(), PosicionActual, FRotator::ZeroRotator);
		}
	}
	//ladrillo2 (subiendo)
	FVector UbicacionInicial_2 = FVector(-3000.0f, -3000.0f, 10.0f);  // Posición del primer bloque
	float DistanciaEntreBloques_2 = 300.0f;  // 
	float AlturaEntreBloques = 120.0f;
	float DesplazamientoDerecha = 200.0f;
	bool Girar = false;
	if (GetWorld())
	{
		for (int i = 0; i < 26; i++)
		{
			FVector PosicionActual_2 = UbicacionInicial_2;
			if (!Girar)
			{
				if (i % 2 == 0)
				{
					PosicionActual_2 += FVector(i * DistanciaEntreBloques_2, DesplazamientoDerecha, i * AlturaEntreBloques);
				}
				else
				{
					PosicionActual_2 += FVector(i * DistanciaEntreBloques_2, 0.0f, i * AlturaEntreBloques);
				}
			}
			else {
				PosicionActual_2 += FVector(9 * DistanciaEntreBloques_2, (i - 15) * DistanciaEntreBloques_2, i * AlturaEntreBloques);
			}
			if (i == 13) {
				Girar = true;
			}
			GetWorld()->SpawnActor<ALadrillo2>(ALadrillo2::StaticClass(), PosicionActual_2, FRotator::ZeroRotator);
		}

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("los bloques desapareceran en 60 segundos"));
	}
}