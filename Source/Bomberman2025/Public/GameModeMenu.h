// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "W_Dificultad.h"
#include "GameModeMenu.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API AGameModeMenu : public AGameModeBase
{
	GENERATED_BODY()


	
public:
	AGameModeMenu();

	AGestorDificultad_Facade* Gestor;
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UW_Dificultad> WidgetClass;

private:
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundWave* MusicaFondo;
	UAudioComponent* AudioComponent;

};
