// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Animation/WidgetAnimation.h"
#include "Components/Image.h"
#include "Templates/Function.h" 
#include "W_PantallaCarga.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UW_PantallaCarga : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	class UBorder* Fondo_Carga;

	UPROPERTY(meta = (BindWidget))
	class UImage* Image_Bomba;

	//Animaciones
	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* Difuminar;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* DifuminadoSalida;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* BombaGiro;

	UFUNCTION()
	void MostrarPantalla();


	void OcultarPantalla(TFunction<void()> AlFinalizar);
};
