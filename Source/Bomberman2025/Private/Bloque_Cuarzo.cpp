// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Cuarzo.h"
ABloque_Cuarzo::ABloque_Cuarzo() {

	if (Mesh) {
		static ConstructorHelpers::FObjectFinder <UMaterialInstance> Material(TEXT("/Script/Engine.MaterialInstanceConstant'/Game/Hechos/Lava/Material/Material_001.Material_001'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);



		}



	}


}
