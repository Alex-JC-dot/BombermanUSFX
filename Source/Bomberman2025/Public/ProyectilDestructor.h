// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystem.h"
#include "ProyectilDestructor.generated.h"

UCLASS()
class BOMBERMAN2025_API AProyectilDestructor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProyectilDestructor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(VisibleAnywhere, Category = "Componentes")
	UStaticMeshComponent* MallaProyectil;

	UPROPERTY(VisibleAnywhere, Category = "Componentes")
	class UProjectileMovementComponent* MovimientoProyectil;


	UPROPERTY(EditDefaultsOnly, Category = "Efectos")
	UParticleSystem* Explosion;
	//UPROPERTY(EditAnywhere, Category = "Daño")
	//float Daño = 50.0f;

	UFUNCTION()
	void OnImpacto(UPrimitiveComponent* Comp, AActor* OtroActor,
		UPrimitiveComponent* OtraComp, FVector Impulso, const FHitResult& Impacto);
	
	int Dano;
	void SetDano(int dano) { Dano = dano; }

	UPROPERTY(EditAnywhere, Category = "sonido")
	USoundBase* Sonido;
};
