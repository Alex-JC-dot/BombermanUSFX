// Fill out your copyright notice in the Description page of Project Settings.



#include "Bloque_Caja.h"
#include "Kismet/GameplayStatics.h"


ABloque_Caja::ABloque_Caja()
{
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/Hechos/Medieval/Material/wood_box.wood_box'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}

	Destructible = true;
}

void ABloque_Caja::Destruir()
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
