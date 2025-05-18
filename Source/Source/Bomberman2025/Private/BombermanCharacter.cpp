// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanCharacter.h"
#include "GameModeLevel2.h"

// Sets default values
ABombermanCharacter::ABombermanCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Personaje"));
	Mesh->SetupAttachment(RootComponent);
	auto asset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Equeletos/source/Bomberman_Caracter.Bomberman_Caracter'"));
	if (asset.Object != nullptr) {
		Mesh->SetStaticMesh(asset.Object);


	}
}

// Called when the game starts or when spawned
void ABombermanCharacter::BeginPlay()
{
	Super::BeginPlay();
	AGameModeLevel2* GameMode = Cast<AGameModeLevel2>(GetWorld()->GetAuthGameMode());
	if (GameMode) {
		int32 Aleatorio = FMath::RandRange(0, GameMode->PuntoVacio.Num()-1);
		Destino = GameMode->PuntoVacio[Aleatorio];
		Activado = true;
	}
}

// Called every frame
void ABombermanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Activado) {
		Movimiento(DeltaTime);
	}
}

// Called to bind functionality to input
void ABombermanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABombermanCharacter::Movimiento(float tiempo)
{
	PosicionActual = GetActorLocation();
	if (Activado) {

		Direccion = (Destino - GetActorLocation()).GetSafeNormal();
		PosicionActual +=   Direccion * Velocidad * tiempo;

	}

	SetActorLocation(PosicionActual);
	
}

