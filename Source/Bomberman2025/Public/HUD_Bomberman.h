// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "W_Dificultad.h"
#include "W_MenuPrincipal.h"
#include "W_BarraVidaEnemigo.h"
#include "W_PantallaGameOver.h"
#include "W_QR.h"
#include "W_MenuConfiguracion.h"
#include "HUD_Bomberman.generated.h"

class UW_Dificultad;
class UW_PantallaCarga;

UCLASS()
class BOMBERMAN2025_API AHUD_Bomberman : public AHUD
{
	GENERATED_BODY()
public:
    AHUD_Bomberman();

    virtual void BeginPlay() override;

    void MostrarMenuPrincipal();

    void MostrarPantallaCarga();

    void MostrarSeleccionDificultad();

    void MostrarPantallaGameOver();

    void OcultarPantallaCarga(TFunction<void()> AlFinalizar);

    void MostrarBarraVidaJefe();

    void OcultarBarraVidaJefe();

    void MostrarPantallaOpciones();

    void MostraQr();

    TSubclassOf<UUserWidget> MenuPrincipal;

    UW_Dificultad* WidgetDificultad;

    TSubclassOf<UUserWidget> PantallaCarga;

    UW_PantallaCarga* WidgetPantallaCarga;
    
    TSubclassOf<UUserWidget> PantallaSeleccionDificultad;

    UW_MenuPrincipal* WidgetMenuPrincipal;


    TSubclassOf<UUserWidget> PantallaGameOver;

    UW_PantallaGameOver* WidgetPantallaGameOver;

    TSubclassOf<UUserWidget> BarraVidaJefeClass;

    UW_BarraVidaEnemigo* WidgetBarraVidaJefe;

    TSubclassOf<UUserWidget> WidgetOpcionesClass;

    UW_MenuConfiguracion* WidgetMenuopciones;

    TSubclassOf<UUserWidget> WidgetQRClass;

    UW_QR* WidgetQr;
};
