// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IConfiguracionNivel.h"
#include "IBuilderEnemigos.h"
#include "EnemigoBase.h"
#include "Explosion.h"
#include "ProyectilDestructor.h"
#include "IBuilderEscenario.h"
#include "Bomberman2025/Bomberman2025.h"
#include "Director_Enemigos.h"
#include "Enemigo_Subterraneo.h"
#include "Enemigo_Subterraneo.h"
#include "GestorNivelMedio.generated.h"

UCLASS()
class BOMBERMAN2025_API AGestorNivelMedio : public AActor, public IIConfiguracionNivel	
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGestorNivelMedio();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Punteros 
	AExplosion* Explosion;
	AProyectilDestructor* Proyectil;
	AEnemigoBase* Enemigo;
	ABomberman2025Character* Player;
	IIBuilderEnemigos* BuilderEnemigos;
	IIBuilderEscenario* BuilderEscenario;
	ADirector_Enemigos* Director;

	virtual void ConfigurarVida() override;
	virtual void ConfigurarDanoBomberman() override;
	virtual void ConfigurarCantidadEnemigos() override;




};
