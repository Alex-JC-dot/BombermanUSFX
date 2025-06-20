// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_ArenaFuerte.h"

ABloque_ArenaFuerte::ABloque_ArenaFuerte()
{
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/Hechos/Desierto/MaterialIndestructible/Stylized_Sand_Bricks.Stylized_Sand_Bricks'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}
}
