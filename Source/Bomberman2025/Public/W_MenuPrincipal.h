// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "W_MenuPrincipal.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UW_MenuPrincipal : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;


    UFUNCTION()
    void SeleccionarDificultad();

    UFUNCTION()
    void Opciones();

    UFUNCTION()
    void Salir();

    UFUNCTION()
    void MostrarQR();

protected:
    //Botones de Dificultad y otros
    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Historia;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Opciones;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Salir;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_QR;

};
