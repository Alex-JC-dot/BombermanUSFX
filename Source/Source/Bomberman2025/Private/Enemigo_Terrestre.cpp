// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Terrestre.h"
AEnemigo_Terrestre::AEnemigo_Terrestre() {
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = Mesh;
	auto Asset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Equeletos/Enemigos/Bot/source/flower/Pokeball_Obj.Pokeball_Obj'"));
	if (Asset.Object != nullptr) {

		Mesh->SetSkeletalMesh(Asset.Object);
	}
}
