// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaberintoTerminado.h"
#include "IBuilderEscenario.h"
#include "BuilderConcreto.generated.h"

UCLASS()
class BOMBERMAN2025_API ABuilderConcreto : public AActor, public IIBuilderEscenario
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderConcreto();
	class ALaberintoTerminado* Laberinto;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void ConstruirBloque() override;
	virtual void ConstruirGrada(int cantidad) override;
	virtual void ConstruirRefugio(int cantidad) override;
	virtual void ConstruirPuerta(int cantidad) override;
	virtual ALaberintoTerminado* GetLaberinto() override;   
    FVector UbicacionInicial;


	//Posiciones 
	TArray<FTransform>Vecindarios = {
	FTransform(FRotator(0.0f, 0.0f, 0.0f), FVector(-5220.0, 610.0, 10.0f)),
	FTransform(FRotator(0.0f, 270.0f, 0.0f), FVector(310, 5110.0, 10.0f)),
	FTransform(FRotator(0.0f, 180.0f, 0.0f), FVector(5090.0, -320, 10.0f)),
	FTransform(FRotator(0.0f, 90.0f,0.0f), FVector(-130.0, -5150.0, 10.0f)),
	};
	TArray<FTransform>Edificios = {
	FTransform (FRotator(0.0f, 0.0f, 0.0f), FVector(-5120.0, -5150.0, 10)),
	FTransform (FRotator(0.0f, 90.0f, 0.0f), FVector(5060.0, -5150.0, 10.0f)),
	FTransform (FRotator(0.0f, 180.0f, 0.0f), FVector(4690.0, 4760.0, 10.0f)),
	FTransform (FRotator(0.0f, 270.0f, 0.0f), FVector(-5180.0, 5220.0, 10)),
	};

};
