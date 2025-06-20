// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "W_HUDBomberman.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UW_HUDBomberman : public UUserWidget
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable)
	void ActualizarBombas(int Bombas);

	UFUNCTION(BlueprintCallable, Category = "Vida")
	void ActualizarVida(float Porcentaje);



protected:

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlock_Bomba;

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* ProgressBar_0;

	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* CanvasPanel_MiniMapa;


};
