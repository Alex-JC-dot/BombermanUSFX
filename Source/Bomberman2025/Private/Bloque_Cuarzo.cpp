// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Cuarzo.h"
ABloque_Cuarzo::ABloque_Cuarzo() {

	if (Mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Copper.M_Metal_Copper'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);



		}



	}


}
