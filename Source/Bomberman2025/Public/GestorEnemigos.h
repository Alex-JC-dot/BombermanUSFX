// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderEscenario.h"
#include "GestorEnemigos.generated.h"

class APuertaNiveles;

UCLASS()
class BOMBERMAN2025_API AGestorEnemigos : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGestorEnemigos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void NotificarMuerte();
	void EstablecerBuilder(TScriptInterface<IIBuilderEscenario> Builder);
	TScriptInterface<IIBuilderEscenario> BuilderActual;

protected:
	UPROPERTY(EditAnywhere, Category = "Puerta")
	TSubclassOf<APuertaNiveles> ClasePuerta;

	UPROPERTY(EditAnywhere, Category = "Configuración")
	FTransform TransformPuerta;

private:
	int32 EnemigosVivos;
	FTimerHandle TimerHandle_Conteo;
	void ContarEnemigos();
	void GenerarPuerta();

	
};
