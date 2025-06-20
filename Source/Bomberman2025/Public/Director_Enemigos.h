

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
	int CantidaEnemigos;
	void SetCantidadEnemigos(int Cantidad) { CantidaEnemigos = Cantidad; }

	void LlamarConstructor(AActor* _Constructor); //Funcion para Llamar a los Builders
	
	void ConstruirHorda();		// Funcion para construir la horda
	class AHordaEnemigos* GetHorda();		//Lo utilizaremos para retornar a nuestro objeto

private:
	
	IIBuilderEnemigos* ConstructorEnemigos;

};
