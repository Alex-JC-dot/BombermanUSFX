// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderEscenario.h"
#include "Director.generated.h"

UCLASS()
class BOMBERMAN2025_API ADirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void LlamarConstructor(AActor* _Constructor);
	void ConstruirLaberinto();
	
	class ALaberintoTerminado* GetLaberinto();

private:
	IIBuilderEscenario* ConstructorEscenario;
};
