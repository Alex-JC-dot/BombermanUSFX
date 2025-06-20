// Fill out your copyright notice in the Description page of Project Settings.


#include "GestorNivelDificil.h"
#include "GameInstance_Datos.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGestorNivelDificil::AGestorNivelDificil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGestorNivelDificil::BeginPlay()
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

void AGestorNivelDificil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGestorNivelDificil::ConfigurarVida()
{
	if (Player)
	{
		Player->SetVida(100);
		Player->SetVidaMax(100);
	}

	UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (Datos)
	{
		Datos->EstablecerVida(100);
		Datos->EstablecerVidaMax(100);
	}
}

void AGestorNivelDificil::ConfigurarDanoBomberman()
{
	if (Enemigo) Enemigo->SetDano(10);
	if (Proyectil) Proyectil->SetDano(6);
	if (Explosion) Explosion->SetDano(8);

	UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (Datos)
	{
		Datos->EstablecerDanoEnemigo(10);
		Datos->EstablecerDanoProyectil(6);
		Datos->EstablecerDanoExplosion(8);
	}
}

void AGestorNivelDificil::ConfigurarCantidadEnemigos()
{
	if (Director)
	{
		Director->SetCantidadEnemigos(11);
	}

	UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (Datos)
	{
		Datos->EstablecerCantidadEnemigos(11);
	}
}