// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Concreto.h"
ABloque_Concreto::ABloque_Concreto() {
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}

}

