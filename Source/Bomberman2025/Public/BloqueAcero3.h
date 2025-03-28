#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BloqueAcero3.generated.h"

UCLASS()
class BOMBERMAN2025_API ABloqueAcero3 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloqueAcero3();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY()
	UStaticMeshComponent* Mesh;

};
