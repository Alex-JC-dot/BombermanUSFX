// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Subterraneo.h"
AEnemigo_Subterraneo::AEnemigo_Subterraneo() {
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	auto Asset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT(" /Script/Engine.StaticMesh'/Game/Hechos/Equeletos/Enemigos/Topo/SM_Digglet.SM_Digglet'"));
	if (Asset.Object != nullptr) {

		Mesh->SetStaticMesh( Asset.Object);
	}


}
