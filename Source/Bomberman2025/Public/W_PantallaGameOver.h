// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "W_PantallaGameOver.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UW_PantallaGameOver : public UUserWidget
{
	GENERATED_BODY()
public:
    virtual void NativeConstruct() override;

protected:
    UFUNCTION()
    void OnReintentarClicked();

    UFUNCTION()
    void OnVolverAlMenuClicked();

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Reiniciar;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_SalirMenu;
};
