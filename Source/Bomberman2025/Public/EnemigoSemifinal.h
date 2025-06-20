// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemigoSemifinal.generated.h"

UCLASS()
class BOMBERMAN2025_API AEnemigoSemifinal : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemigoSemifinal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UStaticMeshComponent* Mesh;


    void RecibirDano(float Cantidad);
    void ActualizarFase();
    void CambiarFase(EFaseDestructor NuevaFase);
    void GestionarVueloYTiempo(float DeltaTime);
    void LanzarProyectil();
    void EntrarEnVuelo();
    void EntrarEnTierra();
    void PerseguirJugador();
    void BuscarJugador();
    FVector ObtenerPosicionEncimaJugador() const;

    FTimerHandle TimerProyectil;
    void IniciarTemporizadorProyectil(float Intervalo);
    void DetenerTemporizadorProyectil();



    // Variables de comportamiento
    EFaseDestructor FaseActual;

    UPROPERTY(EditAnywhere)
    float SaludMaxima = 1000.0f;

    UPROPERTY(VisibleAnywhere)
    float SaludActual;

    /*UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> ClaseProyectil;*/

    UPROPERTY(EditAnywhere)
    float AlturaVuelo = 800.0f;

    UPROPERTY(EditAnywhere)
    float VelocidadTierra = 500.0f;

    UPROPERTY(EditAnywhere)
    float IntervaloProyectil = 3.0f;

    UPROPERTY(EditAnywhere, Category = "Combate")
    TSubclassOf<AActor> ClaseProyectil;


    // Timers
    float TiempoEnVuelo;
    float TiempoEnTierra;
    float TiempoVueloMax;
    float TiempoTierraMax;

    bool bEnVuelo = false;
    bool bEstaMuerto = false;
    bool bEstaCaminando = false;

    AActor* Jugador;
};

UENUM(BlueprintType)
enum class EFaseDestructor : uint8
{
    Fase1,
    Fase2,
    Fase3
};
