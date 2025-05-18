// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Aereo.h"

AEnemigo_Aereo::AEnemigo_Aereo() {
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	auto Asset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT(" /Script/Engine.StaticMesh'/Game/Hechos/Equeletos/Enemigos/globo/SM_MERGED_StaticMeshActor_21.SM_MERGED_StaticMeshActor_21'"));
	if (Asset.Object != nullptr) {

		Mesh->SetStaticMesh(Asset.Object);
	}




}