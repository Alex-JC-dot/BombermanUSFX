// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "Enemigo_Subterraneo.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API AEnemigo_Subterraneo : public AEnemigo
{
	GENERATED_BODY()
	
public:
	AEnemigo_Subterraneo();
	virtual IMyPrototype* Clone() override;
protected:
	virtual void Tick(float DeltaTime) override;
;	
};
