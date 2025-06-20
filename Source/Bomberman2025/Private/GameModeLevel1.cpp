// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModeLevel1.h"
#include "Director.h"
#include "BuilderConcreto.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"

AGameModeLevel1::AGameModeLevel1()
{
	static ConstructorHelpers::FObjectFinder<USoundWave> SonidoAsset(TEXT("/Script/Engine.SoundWave'/Game/GameModeCasero/Sonidos/SpotiMate_io_-_Bomberman_Theme__Area_1__-_Video_Game_Players.SpotiMate_io_-_Bomberman_Theme__Area_1__-_Video_Game_Players'")); // Ruta correcta para el sonido
	if (SonidoAsset.Succeeded())
	{
		MusicaStage1 = SonidoAsset.Object; 
	}
}
    
void AGameModeLevel1::BeginPlay()
{
    Super::BeginPlay();
    if (MusicaStage1)
    {
        UGameplayStatics::PlaySound2D(GetWorld(), MusicaStage1, 0.5f);
    }

    // Mostrar cursor del mouse
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (PC)
    {
        PC->bShowMouseCursor = true;
        PC->SetInputMode(FInputModeUIOnly()); 
    }
    
}
