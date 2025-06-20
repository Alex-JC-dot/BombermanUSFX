#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "GestorEnemigos.h"
#include "AIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "Bomberman2025/Bomberman2025Character.h"
#include "Components/ProgressBar.h"
#include "EnemigoBase.generated.h"

UCLASS()
class BOMBERMAN2025_API AEnemigoBase : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemigoBase();



public:
	void RecibirDanio();


	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
public:
	// ====== Animaciones ======
	UPROPERTY(EditAnywhere, Category = "Animaciones")
	UAnimSequence* AnimacionCaminar;

	UPROPERTY(EditAnywhere, Category = "Animaciones")
	UAnimSequence* AnimacionIdle;

	UPROPERTY(EditAnywhere, Category = "Animaciones")
	UAnimSequence* AnimacionAtaque;

	UPROPERTY(EditAnywhere, Category = "Animaciones")
	UAnimSequence* AnimacionMorir;

	// ====== Combate ======
	UPROPERTY(EditAnywhere, Category = "Combate")

	float Vida = 100;
	float VidaMaxima = 100;
	float DanioAtaque = 20;
	float RangoAtaque = 150.0f;
	float Dano=20.0f;

	void SetDano(float NuevoDano) { Dano = NuevoDano; }

	void Destruir();
	void ReproducirAnimacionInicial();
	virtual float GetDanio();
	void Atacar();
	void TerminarAtaque();
	void AlTerminarMovimiento(FAIRequestID RequestID, const FPathFollowingResult& Resultado);
	virtual float GetVida() {return Vida ; }
	FTimerHandle TemporizadorMuerte;

	float DistanciaAtaque = 200.0f;
	bool bPuedeAtacar = true;
	bool bYaSiguiendoJugador = false;
	bool bEstaMuerto = false;
	bool bEstaAtacando = false;
	bool bEstaCaminando = false;
	bool ObtenerPuntoAleatorioEnNavMesh(FVector& PuntoDestino);


	AActor* ObtenerJugador() const;

	// Cambiar el comportamiento actual
	virtual void CambiarComportamiento(EComportamiento NuevoComportamiento);

	// Punto aleatorio para patrullar
	FVector GenerarPuntoAleatorio();

	//// Iniciar el comportamiento de escape
	//void IniciarEscape();
	//// Detener el comportamiento de escape
	//void TerminarEscape();

	//// Añade esta propiedad para guardar la última posición de bomba detectada
	//UPROPERTY()
	//FVector UltimaPosicionBomba;

	EComportamiento EstadoAnterior;

	FTimerHandle TimerHandle_Escape;
	FTimerHandle TemporizadorAtaque;


	//bool bEstaEscapando = false;
	UPROPERTY()
	class AGestorEnemigos* GestorEnemigos;
	void AsignarGestor(AGestorEnemigos* Gestor);

	UPROPERTY()
	class UEnemigoComportamiento* ComportamientoActual;

	UPROPERTY(EditAnywhere)
	class UEnemigoComportamiento* ComportamientoPatrullar;

	UPROPERTY(EditAnywhere)
	class UEnemigoComportamiento* ComportamientoPerseguir;

	/*UPROPERTY(EditAnywhere)
	class UEnemigoComportamiento* ComportamientoEscapar;*/

	EComportamiento EstadoActual;

	UWidgetComponent* BarraDeVidaWidget;

	ABomberman2025Character* Bomberman;
};

UENUM(BlueprintType)
enum class EComportamiento : uint8
{
	Patrullar     UMETA(DisplayName = "Patrullar"),
	Perseguir     UMETA(DisplayName = "Perseguir"),
	//Escapar       UMETA(DisplayName = "Escapar")
};

