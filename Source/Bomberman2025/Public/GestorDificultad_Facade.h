// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GestorNivelFAcil.h"
#include "GestorNivelMedio.h"
#include "GestorNivelDificil.h"
#include "GestorDificultad_Facade.generated.h"

UCLASS()
class BOMBERMAN2025_API AGestorDificultad_Facade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGestorDificultad_Facade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void ConfigurarNivel(int Dificultad);

	AGestorNivelFAcil* GestorFacil;
	AGestorNivelMedio* GestorMedio;
	AGestorNivelDificil* GestorDificil;
private:
	AActor* GestorActual;

};
