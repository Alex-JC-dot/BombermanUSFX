// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "W_BarraVidaEnemigo.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UW_BarraVidaEnemigo : public UUserWidget
{
	GENERATED_BODY()
	
public:


    UFUNCTION(BlueprintCallable, Category = "Vida")
    void ActualizarBarraVida(float VidaActual, float VidaMaxima);

protected:

    virtual void NativeConstruct() override;

    // Referencia al ProgressBar del widget
    UPROPERTY(meta = (BindWidget))
    UProgressBar* VidaBarra;
};
