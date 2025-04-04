// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Ladrillo.h"
ABloque_Ladrillo::ABloque_Ladrillo() {
	auto AssetMaterial = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
	if (AssetMaterial.Object) {

		Mesh->SetMaterial(0, AssetMaterial.Object);
	}


		
}
