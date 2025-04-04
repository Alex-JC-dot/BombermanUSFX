// Fill out your copyright notice in the Description page of Project Settings.
#include "Bloque_Madera.h"
ABloque_Madera::ABloque_Madera() 
{
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}


}


