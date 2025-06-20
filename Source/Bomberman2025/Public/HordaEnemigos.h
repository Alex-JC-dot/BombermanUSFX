//Este sera el producto fina;

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HordaEnemigos.generated.h"

UCLASS()
class BOMBERMAN2025_API AHordaEnemigos : public AActor
{
	GENERATED_BODY()
	
public:	

	AHordaEnemigos();

protected:
	
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	TArray<TArray<int>>PosicionPeon = {

	{2,1,1,2},
	{1,1,1,1}, 
	{1,1,1,1},
	{2,1,1,2},
	};

};
