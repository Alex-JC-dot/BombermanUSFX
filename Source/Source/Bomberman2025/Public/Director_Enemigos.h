

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderEnemigos.h"
#include "Director_Enemigos.generated.h"

UCLASS()
class BOMBERMAN2025_API ADirector_Enemigos : public AActor
{
	GENERATED_BODY()
	
public:	

	ADirector_Enemigos();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	void LlamarConstructor(AActor* _Constructor);
	void ConstruirHorda();
	class AHordaEnemigos* GetHorda();

private:
	IIBuilderEnemigos* ConstructorEnemigos;
};
