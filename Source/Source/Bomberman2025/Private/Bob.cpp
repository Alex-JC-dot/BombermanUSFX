


#include "Bob.h"

ABob::ABob()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Script/Engine.StaticMesh'/Game/Hechos/Pokeball/Pokeball.Pokeball'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}	
}
void ABob::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(10);
	SetActorLocation(FVector(0.0f, 0.0f, 100.0f));
}
void ABob::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Green, TEXT("💀 ¡Bob ha sido eliminado!"));
	}
}

void ABob::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


