// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoBase.h"
#include "EnemigoBase_Golbin.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API AEnemigoBase_Golbin : public AEnemigoBase
{
	GENERATED_BODY()
private:
	virtual void BeginPlay() override;

public:
	AEnemigoBase_Golbin();

	virtual float GetDanio() override;
};
