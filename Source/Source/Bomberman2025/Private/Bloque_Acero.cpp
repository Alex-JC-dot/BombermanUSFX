// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Acero.h"
ABloque_Acero::ABloque_Acero() 
{
	auto AssetMaterial = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));
	if (AssetMaterial.Object != nullptr) {
		Mesh->SetMaterial(0,AssetMaterial.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Peligro(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Ramp.SM_Ramp'"));
		if (Peligro.Succeeded()) {
			MeshTemporal = Peligro.Object;

		}
		


}

void ABloque_Acero::BeginPlay()
{
	Super::BeginPlay();
	NombreBloque = "Bloque Acero";
}
