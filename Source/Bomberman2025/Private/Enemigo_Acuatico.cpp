// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Acuatico.h"
AEnemigo_Acuatico::AEnemigo_Acuatico() {
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = Mesh;
	auto Asset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Equeletos/Enemigos/Rana/Omanyte/Pokeball_Obj.Pokeball_Obj'"));
	if (Asset.Object != nullptr) {

		Mesh->SetSkeletalMesh( Asset.Object);
	}
}
