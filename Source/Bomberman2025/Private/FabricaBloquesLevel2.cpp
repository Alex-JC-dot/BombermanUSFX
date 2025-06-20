// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaBloquesLevel2.h"
#include "Bloque_Acero.h"
#include "Bloque_Concreto.h"
#include "Bloque_Ladrillo.h"
#include "Bloque_Madera.h"
void AFabricaBloquesLevel2::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Iniciando la creación de bloques..."));

	//CrearBloquesAutomaticamente();
}
//ABloque* AFabricaBloquesLevel2::CrearBloque(FString TipoBloque)
//{
//	//Select which potion to spawn depending on the passed string
//	if (TipoBloque.Equals("Acero")) {
//		return GetWorld()->SpawnActor<ABloque_Acero>
//			(ABloque_Acero::StaticClass());
//	}
//	else if (TipoBloque.Equals("Madera")) {
//		return GetWorld()->SpawnActor<ABloque_Madera>
//			(ABloque_Madera::StaticClass());
//	}
//	else if (TipoBloque.Equals("Concreto")) {
//		return GetWorld()->SpawnActor<ABloque_Concreto>
//			(ABloque_Concreto::StaticClass());
//	}
//	else if (TipoBloque.Equals("Ladrillo")) {
//		return GetWorld()->SpawnActor<ABloque_Ladrillo>
//			(ABloque_Ladrillo::StaticClass());
//	}
//	else return nullptr; //Return null if the string isn't valid
//}

//void AFabricaBloquesLevel2::CrearBloquesAutomaticamente()
//{
//	TArray<FString> TiposDeBloques = { "Acero", "Madera", "Concreto", "Ladrillo" };
//	FVector Posicion = FVector(0, 0, 400); // Posición de inicio (puedes cambiarla)
//
//	// Crear un bloque por cada tipo en el array
//	for (FString Tipo : TiposDeBloques)
//	{
//		ABloque* NuevoBloque = CrearBloque(Tipo); // Usamos tu método de fábrica para crear el bloque
//		if (NuevoBloque)
//		{
//			// Establecer la posición del bloque en el mundo
//			NuevoBloque->SetActorLocation(Posicion);
//
//			// Incrementar la posición para el siguiente bloque (puedes personalizar esto)
//			Posicion.X += 200;  // Ejemplo de mover 200 unidades a la derecha
//		}
//	}
//
//}
