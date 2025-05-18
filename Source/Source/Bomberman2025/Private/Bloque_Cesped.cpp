// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Cesped.h"

ABloque_Cesped::ABloque_Cesped()
{
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/Hechos/Urbano/Pasto/Scene_-_Root_Mat.Scene_-_Root_Mat'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}

}
