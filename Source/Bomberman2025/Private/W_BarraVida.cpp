// Fill out your copyright notice in the Description page of Project Settings.


#include "W_BarraVida.h"

void UW_BarraVida::NativeConstruct()
{
    Super::NativeConstruct();
    if (ProgressBar_Enemigo)
    {
        ProgressBar_Enemigo->SetPercent(1.0f); 
    }
}
void UW_BarraVida::ActualizarBarraVida(float Porcentaje)
{
    if (ProgressBar_Enemigo)
    {
        ProgressBar_Enemigo->SetPercent(Porcentaje);
    }
}