// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque_Ladrillo.h"
ABloque_Ladrillo::ABloque_Ladrillo() {
	auto AssetMaterial = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
	if (AssetMaterial.Object) {

		Mesh->SetMaterial(0, AssetMaterial.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial>Auxiliar(TEXT(" /Script/Engine.Material'/Game/StarterContent/Materials/M_CobbleStone_Pebble.M_CobbleStone_Pebble'"));
	if (Auxiliar.Succeeded()) {
		Material3= Auxiliar.Object;
	}
	Subiendo = true;
	
}
void ABloque_Ladrillo::BeginPlay()
{
	Super::BeginPlay();
	NombreBloque = "Bloque Ladrillo";
}

// Called every frame
void ABloque_Ladrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*PosicionActual = GetActorLocation();
	if (PosicionActual.Z >= alturaMax) {
		Subiendo = false;
	}
	else if (PosicionActual.Z <= 0) {
		Subiendo = true;
	}

	// Mover el bloque
	MoverBloque(DeltaTime);q
	*/
}
/*void ABloque_Ladrillo::MoverBloque(float Tiempo)
{
	PosicionActual = GetActorLocation();
	if (Subiendo) {
		PosicionActual.Z += Tiempo * velocidad;
	}
	else {
		PosicionActual.Z -= Tiempo * velocidad;
	}
	SetActorLocation(PosicionActual);

}
*/

