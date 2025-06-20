// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Acero.h"
ABloque_Acero::ABloque_Acero() 
{
	auto AssetMaterial = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/ Script / Engine.Material'/Game/StarterContent/Materials/M_CobbleStone_Smooth.M_CobbleStone_Smooth'"));
	if (AssetMaterial.Object != nullptr) {
		Mesh->SetMaterial(0,AssetMaterial.Object);
	}
}
	
void ABloque_Acero::BeginPlay()
{
	Super::BeginPlay();
	NombreBloque = "Bloque Acero";
}
