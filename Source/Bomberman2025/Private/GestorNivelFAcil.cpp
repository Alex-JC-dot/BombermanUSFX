#include "GestorNivelFAcil.h"
#include "GameInstance_Datos.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AGestorNivelFAcil::AGestorNivelFAcil()
{
 
	PrimaryActorTick.bCanEverTick = true;

}

void AGestorNivelFAcil::BeginPlay()
{
	Super::BeginPlay();
	Player = Cast<ABomberman2025Character>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	TArray<AActor*> EnemigosEncontrados;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemigoBase::StaticClass(), EnemigosEncontrados);
	if (EnemigosEncontrados.Num() > 0)
	{
		Enemigo = Cast<AEnemigoBase>(EnemigosEncontrados[0]);
	}

	Explosion = Cast<AExplosion>(UGameplayStatics::GetActorOfClass(GetWorld(), AExplosion::StaticClass()));

	Proyectil = Cast<AProyectilDestructor>(UGameplayStatics::GetActorOfClass(GetWorld(), AProyectilDestructor::StaticClass()));

	Director = Cast<ADirector_Enemigos>(UGameplayStatics::GetActorOfClass(GetWorld(), ADirector_Enemigos::StaticClass()));

	ConfigurarVida();
	ConfigurarDanoBomberman();
	ConfigurarCantidadEnemigos();
}

void AGestorNivelFAcil::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called every frame
void AGestorNivelFAcil::ConfigurarVida()
{
	if (Player) {
		Player->SetVida(250);
		Player->SetVidaMax(250);
	}
    UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
    if (Datos)
    {
        Datos->EstablecerVida(250);
        Datos->EstablecerVidaMax(250);
    }
}

void AGestorNivelFAcil::ConfigurarDanoBomberman()
{
    if(Enemigo)Enemigo->SetDano(10);
    if(Proyectil)Proyectil->SetDano(5);
    if(Explosion)Explosion->SetDano(8);

    UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
    if (Datos)
    {
        Datos->EstablecerDanoEnemigo(10);
        Datos->EstablecerDanoProyectil(5);
        Datos->EstablecerDanoExplosion(8);
    }
}

void AGestorNivelFAcil::ConfigurarCantidadEnemigos()
{
	if (Director) {
		Director->SetCantidadEnemigos(1);
	}
    UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
    if (Datos)
    {
        Datos->EstablecerCantidadEnemigos(6);
    }
}
