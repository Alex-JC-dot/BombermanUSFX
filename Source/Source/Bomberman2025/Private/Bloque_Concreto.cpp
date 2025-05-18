// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Concreto.h"
ABloque_Concreto::ABloque_Concreto() {
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial>Auxiliar(TEXT(" /Script/Engine.Material'/Game/StarterContent/Materials/M_Rock_Sandstone.M_Rock_Sandstone'"));
	if (Auxiliar.Succeeded()) {
		Material= Auxiliar.Object;
	}

}
void ABloque_Concreto::BeginPlay()
{
	Super::BeginPlay();
	NombreBloque = "Bloque Concreto";
}

