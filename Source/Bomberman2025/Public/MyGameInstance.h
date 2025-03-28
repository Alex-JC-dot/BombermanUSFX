// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UMyGameInstance : public UGameInstance
{

	GENERATED_BODY()
public:    
	UMyGameInstance();
	// Variable para almacenar el personaje por defecto
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuración")
	TSubclassOf<APawn> DefaultPlayerPawn;
	
};
