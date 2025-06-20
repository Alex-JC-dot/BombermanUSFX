// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "W_BarraVida.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UW_BarraVida : public UUserWidget
{
    GENERATED_BODY()


public:
    UFUNCTION(BlueprintCallable)
    void ActualizarBarraVida(float Porcentaje);

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    UProgressBar* ProgressBar_Enemigo;

};

