// Copyright Epic Games, Inc. All Rights Reserved.
// Copyright Epic Games, Inc. All Rights Reserved.

#include "Bomberman2025GameMode.h"
#include "Bomberman2025Character.h"
#include "Director.h"
#include "GameInstance_Datos.h"
#include "BuilderConcreto.h"
#include "HUD_Bomberman.h"
#include "UObject/ConstructorHelpers.h"

ABomberman2025GameMode::ABomberman2025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	HUDClass = AHUD_Bomberman::StaticClass();

}
void ABomberman2025GameMode::BeginPlay()
{
	GestorEscenarios = NewObject<UGestorEscenarios>(this);
	if (UGameInstance_Datos* GI = Cast<UGameInstance_Datos>(GetGameInstance()))
	{
		CambiarEscenario(GI->EscenarioActual);
	}

}

void ABomberman2025GameMode::CambiarEscenario(ETipoEscenario NuevoEscenario)
{

	if (GestorEscenarios)
	{
		UWorld* World = GetWorld();
		GestorEscenarios->ConstruirEscenario(World, NuevoEscenario);


	}
}

		
