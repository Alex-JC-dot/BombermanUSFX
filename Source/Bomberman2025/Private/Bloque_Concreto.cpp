// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Concreto.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"


ABloque_Concreto::ABloque_Concreto() {
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Script/Engine.MaterialInstanceConstant'/Game/Hechos/Artico/Material/Material.Material'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UNiagaraSystem> NiagaraAurAAsset(TEXT(" Niagara.NiagaraSystem'/Game/sA_Megapack_v1/sA_SkillSet_1/Fx/NiagaraSystems/NS_Projectile_Hit.NS_Projectile_Hit'"));
	if (NiagaraAurAAsset.Succeeded())
	{
		NiagaraNive = NiagaraAurAAsset.Object;
	}
	Destructible = true;
}
void ABloque_Concreto::Destruir()
{
    if (Destructible && NiagaraNive)
    {
        // Ubicación: un poco desplazada del actor original
        FVector Ubicacion = GetActorLocation() + FVector(200.0f, 200.0f, 200.0f);

        // Rotación en cero
        FRotator Rotacion = FRotator::ZeroRotator;

        // Escala del sistema de partículas
        FVector Escala = FVector(5.0f);

        // Crear transformación completa
        FTransform TransformParticula(Rotacion, Ubicacion, Escala);

        // Instanciar el sistema Niagara
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(
            GetWorld(),
            NiagaraNive,
            TransformParticula.GetLocation(),
            TransformParticula.GetRotation().Rotator(),
            TransformParticula.GetScale3D()
        );

        // Destruir el actor
        Destroy();
    }
}
void ABloque_Concreto::BeginPlay()
{
	Super::BeginPlay();
	NombreBloque = "Bloque Concreto";
}

