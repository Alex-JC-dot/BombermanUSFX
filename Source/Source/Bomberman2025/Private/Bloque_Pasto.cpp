// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Pasto.h"

ABloque_Pasto::ABloque_Pasto(){

	if (Mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Ground_Grass.M_Ground_Grass'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);



		}



	}


}
