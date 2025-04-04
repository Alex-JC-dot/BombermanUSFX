// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Hielo.h"
ABloque_Hielo::ABloque_Hielo()
{
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Rock_Slate.M_Rock_Slate'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}


}
