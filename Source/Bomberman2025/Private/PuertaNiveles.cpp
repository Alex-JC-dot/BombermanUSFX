// Fill out your copyright notice in the Description page of Project Settings.


#include "PuertaNiveles.h"
#include "HUD_Bomberman.h"
#include "GestorEscenarios.h"
#include "GameInstance_Datos.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
APuertaNiveles::APuertaNiveles()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
	RootComponent = Mesh;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/door/Puerta/Puerta.Puerta'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}

	Mesh->SetWorldScale3D(FVector(0.5f, 0.5f, 0.7f));
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Mesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	Mesh->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void APuertaNiveles::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuertaNiveles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APuertaNiveles::NotifyActorBeginOverlap(AActor* OtherActor)
{
    if (ABomberman2025Character* Jugador = Cast<ABomberman2025Character>(OtherActor))
    {
        Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

        FName NivelAbrir = UGestorEscenarios::ObtenerNombreNivelDesdeEscenario(EscenarioDestino);

        if (UGameInstance_Datos* GI = Cast<UGameInstance_Datos>(GetGameInstance()))
        {
            GI->EscenarioActual = EscenarioDestino;
        }


        if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
        {
            if (AHUD_Bomberman* HUD = Cast<AHUD_Bomberman>(PC->GetHUD()))
            {
                HUD->MostrarPantallaCarga(); 
            }
        }

        FTimerHandle TimerHandleEspera;
        GetWorldTimerManager().SetTimer(TimerHandleEspera,FTimerDelegate::CreateLambda([this, NivelAbrir]() {UGameplayStatics::OpenLevel(this, NivelAbrir);}),5.0f,false);
    }
}

