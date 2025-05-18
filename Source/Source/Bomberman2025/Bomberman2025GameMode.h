// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BuilderConcreto.h"
#include "Director.h"
#include "Bomberman2025GameMode.generated.h"

UCLASS()
class ABomberman2025GameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ABomberman2025GameMode();

public:
    virtual void BeginPlay() override;
private:
    ADirector* Director;
    ABuilderConcreto* BuilderConcreto;
    
};