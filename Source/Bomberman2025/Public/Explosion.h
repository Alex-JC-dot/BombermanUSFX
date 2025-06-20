// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h" 
#include "Explosion.generated.h"


UCLASS()
class BOMBERMAN2025_API AExplosion : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplosion();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* ExplosionMesh;
	UPROPERTY()
	UAnimSequence* ExplosionAnimation;
	float Duracion= 5.0f;
	UBoxComponent* BoxComp;
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool bFromSweep, const FHitResult& Hit);
	UPROPERTY(EditAnywhere, Category = "sonido")
	USoundBase* Sonido;
	
	int dano;

	void SetDano(int Dano) { dano = Dano; }

};
