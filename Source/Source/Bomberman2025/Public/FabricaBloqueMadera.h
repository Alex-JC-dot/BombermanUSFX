// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbstractFabrica.h"
#include "FabricaBloqueMadera.generated.h"

class ABloque;
class AEnemigo;
class AArbolJungla;
class AMonumento;

UCLASS()
class BOMBERMAN2025_API AFabricaBloqueMadera : public AActor, public IAbstractFabrica
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaBloqueMadera();
	virtual ABloque* CrearBloqueMadera(FVector Pos) override;
	virtual AEnemigo* CrearEnemigoMadera(FVector Posicion) override;
	virtual AArbolJungla* CrerarArbolMadera(FVector Posicion) override;
	virtual APlanta* CrearPlanta(FVector Posicion) override;
	virtual AMonumento* CrearMonumento(FVector Posicion, FRotator Rotacion) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
