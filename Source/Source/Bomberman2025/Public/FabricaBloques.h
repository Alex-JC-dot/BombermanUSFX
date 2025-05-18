// Fill out your copyright notice in thes Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.h"
#include "FabricaBloques.generated.h"

UCLASS()
class BOMBERMAN2025_API AFabricaBloques : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaBloques();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ABloque* CrearBloque(FString TipoBloque, FVector posicion);
	//PURE_VIRTUAL(AFabricaBloques::CrearBloque, return nullptr;);

	//ABloque* OrdenarBloque(FString TipoBloque);

};
