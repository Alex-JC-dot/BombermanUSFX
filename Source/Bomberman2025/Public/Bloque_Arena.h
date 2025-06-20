// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "Bloque_Arena.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API ABloque_Arena : public ABloque
{
	GENERATED_BODY()
public:
	ABloque_Arena();
	virtual void Destruir() override;


};
