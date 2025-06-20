// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Bomberman2025/Bomberman2025Character.h"
#include "PowerUpVelocidad.generated.h"

UCLASS()
class BOMBERMAN2025_API APowerUpVelocidad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerUpVelocidad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* Collision;

	void RestaurarVelocidad();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);

	UPROPERTY()
	ABomberman2025Character* JugadorAfectado = nullptr;

	FTimerHandle TimerHandle_Velocidad;
	float VelocidadOriginal = 0.0f;
	float DuracionVelocidad = 5.0f; // segundos
};


