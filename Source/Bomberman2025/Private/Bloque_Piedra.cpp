// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Piedra.h"

ABloque_Piedra::ABloque_Piedra()
{
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/Hechos/Cementerio/Material2/Scene_-_Root.Scene_-_Root'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}
}
