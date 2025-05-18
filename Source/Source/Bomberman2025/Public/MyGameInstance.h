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
	FString Nombre_Jugador;
	int Puntacion;
	virtual void Init() override;
	UFUNCTION(BlueprintCallable)
	void NombreJugador(const FString& nombre);

};
