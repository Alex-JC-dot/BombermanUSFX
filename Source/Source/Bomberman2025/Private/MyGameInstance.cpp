#include "MyGameInstance.h"

#include "UObject/ConstructorHelpers.h"


void UMyGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("¡MyGameInstance ha iniciado!"));
	Nombre_Jugador = "Desconocido";
	Puntacion = 0;
}

void UMyGameInstance::NombreJugador(const FString& nombre)
{
	Nombre_Jugador = nombre;
	UE_LOG(LogTemp, Warning, TEXT("Nuevo nombre del jugador: %s"), *Nombre_Jugador);
}
