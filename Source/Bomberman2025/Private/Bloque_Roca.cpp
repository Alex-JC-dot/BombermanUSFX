// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Roca.h"
#include "Kismet/GameplayStatics.h"


ABloque_Roca::ABloque_Roca()
{
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/Hechos/Lava/Material/Roca.Roca'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}
	Destructible = true;
}

void ABloque_Roca::Destruir()
{
	if (Explosion) {
		FVector Ubicacion = GetActorLocation() + FVector(200.0f, 200.0f, 200.0f);
		FRotator Rotacion = FRotator::ZeroRotator;
		FVector Escala = FVector(5.0);
		FTransform TransformParticula(Rotacion, Ubicacion, Escala);

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion, TransformParticula);
	}
	Destroy();
}
