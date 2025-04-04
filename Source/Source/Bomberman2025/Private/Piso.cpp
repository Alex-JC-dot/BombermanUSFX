// Fill out your copyright notice in the Description page of Project Settings.


#include "Piso.h"

// Sets default values
APiso::APiso()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
	RootComponent = Mesh;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));
		if (MeshAsset.Object != nullptr) {
			Mesh->SetStaticMesh(MeshAsset.Object);
		}
		Mesh->SetWorldScale3D(FVector(8.0f, 8.0f, 8.0f));
		auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("/Script/Engine.Material'/Game/Hechos/alley-brick-wall-ue/MaterialMOD1.MaterialMOD1'"));
		if (MaterialAsset.Object != nullptr) {

			Mesh->SetMaterial(0, MaterialAsset.Object);
		}
		
		MuroIzquierdo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroIzquierdo"));
		MuroDerecho = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroDerecho"));
		MuroFrontal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroFrontal"));
		MuroTrasero = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroTrasero"));

		MuroIzquierdo->SetupAttachment(RootComponent);
		MuroDerecho->SetupAttachment(RootComponent);
		MuroFrontal->SetupAttachment(RootComponent);
		MuroTrasero->SetupAttachment(RootComponent);
		auto MuroAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));
		if (MuroAsset.Succeeded())
		{
			MuroIzquierdo->SetStaticMesh(MuroAsset.Object);
			MuroDerecho->SetStaticMesh(MuroAsset.Object);
			MuroFrontal->SetStaticMesh(MuroAsset.Object);
			MuroTrasero->SetStaticMesh(MuroAsset.Object);
		}

		float MuroAltura = 1.0f;
		float MuroGrosor = 0.1f;
		float MuroLargo = 10.0f;
		MuroFrontal->SetWorldScale3D(FVector(MuroLargo, MuroGrosor, MuroAltura));
		MuroTrasero->SetWorldScale3D(FVector(MuroLargo, MuroGrosor, MuroAltura));



		MuroFrontal->SetRelativeLocation(FVector(-500.0f, -500.0f, -10.0f));
		MuroTrasero->SetRelativeLocation(FVector(-500.0f, 500.0f, -10.0f));

		MuroIzquierdo->SetWorldScale3D(FVector(MuroGrosor, MuroLargo, MuroAltura));
		MuroDerecho->SetWorldScale3D(FVector(MuroGrosor, MuroLargo, MuroAltura));


		MuroIzquierdo->SetRelativeLocation(FVector(-500.0f, -500.0f, -10.0f));
		MuroDerecho->SetRelativeLocation(FVector(500.0f, -500.0f, -10.0f));
	;
}

void APiso::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APiso::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

