#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Director.h"
#include "BuilderHielo.h"
#include "GameModeLevel2.generated.h"

// Ensure GENERATED_BODY is not inside any conditional preprocessor block
UCLASS()
class BOMBERMAN2025_API AGameModeLevel2 : public AGameModeBase
{
    GENERATED_BODY()
public:
    AGameModeLevel2();

protected:
    virtual void BeginPlay() override;
    ABuilderHielo* BuilderHielo;
    ADirector* Director;

};