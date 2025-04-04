#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"
/**
 * 
 */
class ABloque;
UCLASS()
class BOMBERMAN2025_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMyGameModeBase();
	public:
    virtual void BeginPlay() override;
public:

	UPROPERTY()
	ABloque* SpawnedActor;
	UFUNCTION()
	void DestroyActorFunction();
	FTimerHandle TimerHandle;
};
