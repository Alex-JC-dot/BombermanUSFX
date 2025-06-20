// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModeMenu.h"
#include "Camera/CameraActor.h"
#include "HUD_Bomberman.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "Kismet/KismetMathLibrary.h"

AGameModeMenu::AGameModeMenu()
{
	//sonido
	static ConstructorHelpers::FObjectFinder<USoundWave> SonidoAsset(TEXT("/Script/Engine.SoundWave'/Game/GameModeCasero/Sonidos/SpotiMate_io_-_Bomberman_Hero__Redial_-_Arcade_Player.SpotiMate_io_-_Bomberman_Hero__Redial_-_Arcade_Player'")); // Ruta correcta para el sonido
	if (SonidoAsset.Succeeded())
	{
		MusicaFondo = SonidoAsset.Object; // Asignación del sonido de colisión
	}
	HUDClass = AHUD_Bomberman::StaticClass();
}

void AGameModeMenu::BeginPlay()
{
	Super::BeginPlay();
	if (MusicaFondo)
	{UGameplayStatics::PlaySound2D(GetWorld(), MusicaFondo, 0.5f);}

	UWorld* World = GetWorld();
	if (!World) return;

	FVector PosicionCamara = FVector(-4400.0f, -2502.0f, 4947.0f);

	// Punto al que debe mirar la cámara (ejemplo: el centro del menú)
	FVector PuntoObjetivo = FVector(-1510.0, -540.0f, 4890.0f); // ? AJUSTA este punto a donde quieres que mire

	// Calcular rotación mirando hacia el objetivo
	FRotator RotacionCamara = UKismetMathLibrary::FindLookAtRotation(PosicionCamara, PuntoObjetivo);

	// Spawnear cámara
	ACameraActor* Camara = World->SpawnActor<ACameraActor>(ACameraActor::StaticClass(), PosicionCamara, RotacionCamara);
	if (!Camara) return;

	// Hacer que el PlayerController use esta cámara
	APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0);
	if (PC)
	{
		PC->SetViewTargetWithBlend(Camara, 0.5f); // Suavizado opcional de la transición
	}
	
}


	

