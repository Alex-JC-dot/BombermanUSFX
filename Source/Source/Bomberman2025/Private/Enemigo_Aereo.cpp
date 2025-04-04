// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Aereo.h"

AEnemigo_Aereo::AEnemigo_Aereo() {

	auto Asset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT(" /Script/Engine.Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));
	if (Asset.Object != nullptr) {

		Mesh->SetMaterial(0, Asset.Object);
	}


}