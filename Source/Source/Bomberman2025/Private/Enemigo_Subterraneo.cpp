// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Subterraneo.h"

AEnemigo_Subterraneo::AEnemigo_Subterraneo() {
	
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	Mesh->SetupAttachment(Colisiones);

	auto Asset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Personajes/Object_218.Object_218'"));
	if (Asset.Object != nullptr) {

		Mesh->SetSkeletalMesh(Asset.Object);
	}
	auto Anim = ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Personajes/Animation123.Animation123'"));
	if (Anim.Succeeded())
	{
		Mesh->PlayAnimation(Anim.Object, true);
	}
}

IMyPrototype* AEnemigo_Subterraneo::Clone()
{


		FActorSpawnParameters Params;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		AEnemigo_Subterraneo* Copia = GetWorld()->SpawnActor<AEnemigo_Subterraneo>(
			this->GetClass(),
			this->GetActorLocation(),
			this->GetActorRotation(),
			Params
		);

		return Cast<IMyPrototype>(Copia);

}

void AEnemigo_Subterraneo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugBox(
		GetWorld(),
		Colisiones->GetComponentLocation(),             // Centro de la caja
		Colisiones->GetScaledBoxExtent(),               // Tamaño
		Colisiones->GetComponentRotation().Quaternion(), // Rotación correcta
		FColor::Red,                                    // Color
		false,                                          // No persistente (solo este frame)
		0.0f,                                           // Tiempo de vida
		0,                                              // Depuración
		2.0f                                            // Grosor
	);
	DistanciaMaxima = 100.0f;
	

}