// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Pasto.h"
#include "Kismet/GameplayStatics.h"


ABloque_Pasto::ABloque_Pasto(){

	if (Mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("/Script/Engine.Material'/Game/Hechos/Antiguo/Pasto/grass.grass'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);

		}
	}
	Destructible = true;

}

void ABloque_Pasto::Destruir()
{
	if (Explosion) {
		FVector Ubicacion = GetActorLocation() +FVector(200.0f, 200.0f,200.0f);
		FRotator Rotacion = FRotator::ZeroRotator;
		FVector Escala = FVector(5.0);
		FTransform TransformParticula(Rotacion, Ubicacion, Escala);

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion,  TransformParticula);
	}
   Destroy();
}
