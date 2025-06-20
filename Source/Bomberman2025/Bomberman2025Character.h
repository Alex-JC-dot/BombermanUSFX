// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "W_HUDBomberman.h"
#include "Bomberman2025Character.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ABomberman2025Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PutBombAction;
public:
	ABomberman2025Character();
	
	int AlcanceExplosion = 2;
	int Vidas = 5;

	int BombasDisponibles = 3;
	int BombasMaximas = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UUserWidget> WidgetClaseHUD;

	UPROPERTY()
	class UW_HUDBomberman* WidgetHUD;

	FTimerHandle TimerHandle_RegenerarBomba;;

	float VidaActual = 250.0f;

	float VidaMaxima = 250.0f;

	FTimerHandle TimerHandle_Parpadeo;

	int ContadorParpadeo = 0;
	
	FTimerHandle TimerHandle_Morir;

	UAnimSequence* AnimacionMorir;


	bool bEstaMuerto = false;
	
	//Sonido
	USoundBase* SonidoColocarBomba;

public:
	void RecibirDano(int dano);
	
	void Morir();

	void Parpadear();

	void SetVidaMax(int VidaMax) { VidaMaxima = VidaMax; }
	void SetVida(int vida) { vida = VidaActual; }
	float ObtenerVidaPorcentaje()
	{
		return VidaActual / VidaMaxima;
	}

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for put a bomb input */
	void PutBom(const FInputActionValue& Value);


	void RegenarBomba();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

