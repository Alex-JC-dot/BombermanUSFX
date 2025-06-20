// Fill out your copyright notice in the Description page of Project Settings.


#include "GestorNivelMedio.h"
#include "GameInstance_Datos.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGestorNivelMedio::AGestorNivelMedio()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}


void AGestorNivelMedio::BeginPlay()
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

void AGestorNivelMedio::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGestorNivelMedio::ConfigurarVida()
{
	if (Player) {
		Player->SetVida(170);
		Player->SetVidaMax(170);
	}
	UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (Datos)
	{
		Datos->EstablecerVida(170);
		Datos->EstablecerVidaMax(170);
	}
}

void AGestorNivelMedio::ConfigurarDanoBomberman()
{
	if(Enemigo)Enemigo->SetDano(10);
	if (Proyectil)Proyectil->SetDano(6);
	if(Explosion)Explosion->SetDano(6);

	UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (Datos)
	{
		Datos->EstablecerDanoEnemigo(10);
		Datos->EstablecerDanoProyectil(6);
		Datos->EstablecerDanoExplosion(6);
	}
}

void AGestorNivelMedio::ConfigurarCantidadEnemigos()
{

	if (Director)
	{
		Director->SetCantidadEnemigos(8);

	}
		UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
		if (Datos)
		{
			Datos->EstablecerCantidadEnemigos(8);
		}
}

