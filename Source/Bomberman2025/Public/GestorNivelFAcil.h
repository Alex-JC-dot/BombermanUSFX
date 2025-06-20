

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IConfiguracionNivel.h"
#include "IBuilderEnemigos.h"
#include "EnemigoBase.h"
#include "Explosion.h"
#include "Director_Enemigos.h"
#include "ProyectilDestructor.h"
#include "IBuilderEscenario.h"
#include "Bomberman2025/Bomberman2025.h"
#include "Enemigo_Subterraneo.h"
#include "GestorNivelFAcil.generated.h"

UCLASS()
class BOMBERMAN2025_API AGestorNivelFAcil : public AActor, public IIConfiguracionNivel
{
	GENERATED_BODY()
	
public:	
	
	AGestorNivelFAcil();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
	//Punteros 
	AExplosion* Explosion;
	AProyectilDestructor* Proyectil;
	AEnemigoBase* Enemigo;
	ABomberman2025Character* Player;
	IIBuilderEnemigos* BuilderEnemigos;
	IIBuilderEscenario* BuilderEscenario;
	ADirector_Enemigos* Director;

	virtual void ConfigurarVida() override;
	virtual void ConfigurarDanoBomberman() override;
	virtual void ConfigurarCantidadEnemigos() override;



};
