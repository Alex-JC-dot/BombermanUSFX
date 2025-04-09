// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Acero.h"
ABloque_Acero::ABloque_Acero() 
{
	auto AssetMaterial = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));
	if (AssetMaterial.Object != nullptr) {
		Mesh->SetMaterial(0,AssetMaterial.Object);


	}




}
