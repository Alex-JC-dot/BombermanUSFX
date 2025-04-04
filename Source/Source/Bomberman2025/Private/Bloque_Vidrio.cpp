// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Vidrio.h"

ABloque_Vidrio::ABloque_Vidrio()
{
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Glass.M_Glass'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}


}
