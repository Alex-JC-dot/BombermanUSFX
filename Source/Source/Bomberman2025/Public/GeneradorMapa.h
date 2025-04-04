
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GeneradorMapa.generated.h"

UCLASS()
class BOMBERMAN2025_API AGeneradorMapa : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeneradorMapa();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void GenerarLaberinto();

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<class AMuro1> ClaseMuro1;

private:
	// Definir el tamaño de la matriz
	static constexpr int filas = 20;
	static constexpr int columnas = 20;

	// Matriz del laberinto
	int MapaLaberinto[filas][columnas];
};