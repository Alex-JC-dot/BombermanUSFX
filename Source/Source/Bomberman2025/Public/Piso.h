// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Piso.generated.h"

UCLASS()
class BOMBERMAN2025_API APiso : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APiso();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY()
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MuroIzquierdo;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MuroDerecho;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MuroFrontal;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MuroTrasero;
};
