// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemigoBase.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "FinalBoss.generated.h"

UENUM(BlueprintType)
enum class EFaseHorda : uint8
{
	Fase1 UMETA(DisplayName = "Fase 1"),
	Fase2 UMETA(DisplayName = "Fase 2"),
	Fase3 UMETA(DisplayName = "Fase 3"),
	Fase4 UMETA(DisplayName = "Fase 4")
};
UCLASS()
class BOMBERMAN2025_API AFinalBoss : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFinalBoss();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    void ActualizarFase();
    void InvocarEnemigos();
    void DetectarYPerseguirJugador();
    void TerminarAtaque();
    void MoveToLocation(const FVector& Destino);

//Animaciones

    UPROPERTY(EditAnywhere, Category = "Animaciones")
    UAnimSequence* AnimacionCaminar;

    UPROPERTY(EditAnywhere, Category = "Animaciones")
    UAnimSequence* AnimacionIdle;

    UPROPERTY(EditAnywhere, Category = "Animaciones")
    UAnimSequence* AnimacionAtaque;

    UPROPERTY(EditAnywhere, Category = "Animaciones")
    UAnimSequence* AnimacionMorir;

    UPROPERTY(EditAnywhere, Category = "Animaciones")
    UAnimSequence* AnimacionGrito;

    UPROPERTY(EditAnywhere, Category = "Animaciones")
    UAnimSequence* AnimacionAtaqueDistancia;

    // Variables de patrullaje
    float TiempoSiguientePatrulla;

    // Estado del jefe
    EFaseHorda FaseActual;

    // Vida y velocidad
    float VidaMaxima;
    float VidaActual;
    float VelocidadBase;
    float RangoAtaque = 500.0f;
    float RangoAtaqueLargo = 1200.0f;

    // Comportamiento
    bool bPersiguiendoJugador;
    bool bEstaMuerto = false;
    bool bEstaAtacando=false;
    bool bEstaCaminando = false;
    bool bBatallaIniciada = false;

    // Tiempo y radio para patrullaje
    float TiempoEntrePatrullas;
    float RadioPatrullaje;

    FTimerHandle TemporizadorAtaque;
    FTimerHandle TemporizadorMuerte;
    FTimerHandle TemporizadorGrito;
    FTimerHandle TemporizadorDano;

public:

    // Lógica de ataque (a implementar)
    void AtacarJugador();
    void RecibirDano(float Cantidad);
    void ReproducirAnimacionInicial();
    void EjecutarGritoEInvocacion();
    void FinalizarGritoEInvocar();
    void AplicarDanoAlJugador();
    void ComenzarBatalla();


    // Clase del enemigo que se va a invocar
    UPROPERTY(EditAnywhere, Category = "Enemigos")
    TSubclassOf<ACharacter> ClaseEnemigoComun;

    UPROPERTY(EditAnywhere, Category = "Enemigos")
    TSubclassOf<ACharacter> ClaseEnemigoFuerte;


    // Particulas 

    //UPROPERTY(EditAnywhere, Category = "Efectos")
    UNiagaraSystem* NiagaraAtaqueFinalizado;


    UPROPERTY(EditDefaultsOnly, Category = "Efectos")
    UNiagaraSystem* EfectoAuraNiagara;

    UPROPERTY(VisibleAnywhere, Category = "Efectos")
    UNiagaraComponent* ComponenteAura;


    //Sonido
    USoundBase* SonidoMuerte;
    USoundBase* SonidoGrito;
    USoundBase* SonidoEspada;
    USoundBase* SonidoBossBattle;

    UPROPERTY()
    UAudioComponent* AudioBossBattle;
};

