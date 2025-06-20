

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bob2.generated.h"

UCLASS()
class BOMBERMAN2025_API ABob2 : public AActor
{
	GENERATED_BODY()

public:
	
	ABob2();

protected:

	virtual void BeginPlay() override;

private:
	float velociad;
	FVector DIstanciaMaxima;
	bool Encendido;

public:
	
	virtual void Tick(float DeltaTime) override;
	UPROPERTY() 
	UStaticMeshComponent* Mesh; 

	void Despegar(float tiempo);
};
