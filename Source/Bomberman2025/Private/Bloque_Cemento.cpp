// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Cemento.h"
#include "Kismet/GameplayStatics.h"


ABloque_Cemento::ABloque_Cemento()
{
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/Hechos/Cementerio/Material/BrickWhite.BrickWhite'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}
	Destructible = true;
}

void ABloque_Cemento::Destruir()
{
	if (Destructible) {
		if (Explosion) {
			FVector Ubicacion = GetActorLocation() + FVector(200.0f, 200.0f, 200.0f);
			FRotator Rotacion = FRotator::ZeroRotator;
			FVector Escala = FVector(5.0);
			FTransform TransformParticula(Rotacion, Ubicacion, Escala);

			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion, TransformParticula);
		}
		Destroy();

	}

}
