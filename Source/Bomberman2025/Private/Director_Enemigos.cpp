


#include "Director_Enemigos.h"
#include "GameInstance_Datos.h"
#include "Kismet/GameplayStatics.h"

ADirector_Enemigos::ADirector_Enemigos()
{

	PrimaryActorTick.bCanEverTick = true;

}

void ADirector_Enemigos::BeginPlay()
{
	Super::BeginPlay();
	UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (Datos)
	{
		CantidaEnemigos = Datos->ObtenerCantidadEnemigos();
	}
}


void ADirector_Enemigos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirector_Enemigos::LlamarConstructor(AActor* _Constructor)
{
	ConstructorEnemigos = Cast<IIBuilderEnemigos>(_Constructor);  // Un cast para para elegir a un builder en especific
}

void ADirector_Enemigos::ConstruirHorda()
{
	ConstructorEnemigos->ConstruirEnemigoMagico(1);		// LLamamos a los metodos del builder para la contruccion 
	ConstructorEnemigos->ContruirEnemigoPeon(CantidaEnemigos);		// LLenamos los parametros de Cantidad
	ConstructorEnemigos->ContruirJefe(CantidaEnemigos);				// 10 peones y 4 jefes 
}

AHordaEnemigos* ADirector_Enemigos::GetHorda()
{
	if (ConstructorEnemigos)
	{
		return ConstructorEnemigos->GetHorda();		 // Para hacer un retorno a nuestro objeto
	}
	return nullptr;
}
	


