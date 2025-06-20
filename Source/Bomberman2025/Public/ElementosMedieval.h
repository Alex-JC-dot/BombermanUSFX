// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElementosMedieval.generated.h"

UCLASS()
class BOMBERMAN2025_API AElementosMedieval : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElementosMedieval();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UStaticMeshComponent* Mesh;
	void EstablecerMalla(UStaticMesh* Malla);
	static UStaticMesh* MeshRuta(const FString& Ruta);

	//Rutas
	FString RutaLago;
	FString RutaCastillo;
	FString RutaCaverna;
	FString RutaCasa;
	FString RutaMercado;
	FString RutaPasto;
	
};
