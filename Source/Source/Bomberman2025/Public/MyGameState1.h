// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MyGameState1.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API AMyGameState1 : public AGameState
{
	GENERATED_BODY()
	AMyGameState1();
	UFUNCTION()
	void SetScore(int32 NewScore);
	UFUNCTION()
	int32 GetScore();
private:
	UPROPERTY()
	int32 CurrentScore;
};
