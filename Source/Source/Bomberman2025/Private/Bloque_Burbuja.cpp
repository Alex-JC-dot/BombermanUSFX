// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Burbuja.h"

ABloque_Burbuja::ABloque_Burbuja() {

	if (Mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Water_Lake.M_Water_Lake'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);



		}



	}


}