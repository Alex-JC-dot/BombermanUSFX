// Fill out your copyright notice in the Description page of Project Settings.


#include "W_BarraVidaEnemigo.h"


void UW_BarraVidaEnemigo::NativeConstruct()
{
    Super::NativeConstruct();

    // Inicialización opcional
    if (VidaBarra)
    {
        VidaBarra->SetPercent(1.0f); // Vida completa al inicio
    }

}


void UW_BarraVidaEnemigo::ActualizarBarraVida(float VidaActual, float VidaMaxima)
{
    if (VidaBarra && VidaMaxima > 0)
    {
        float Porcentaje = FMath::Clamp(VidaActual / VidaMaxima, 0.0f, 1.0f);
        VidaBarra->SetPercent(Porcentaje);
    }

}


