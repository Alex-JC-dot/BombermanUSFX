// Fill out your copyright notice in the Description page of Project Settings.


#include "W_PantallaCarga.h"
#include "Templates/Function.h"

void UW_PantallaCarga::MostrarPantalla()
{
    if (Fondo_Carga)
        Fondo_Carga->SetVisibility(ESlateVisibility::Visible);

    if (Image_Bomba)
        Image_Bomba->SetVisibility(ESlateVisibility::Visible);

    if (Difuminar)
        PlayAnimation(Difuminar);

    if (BombaGiro)
        PlayAnimation(BombaGiro, 0.f, 0, EUMGSequencePlayMode::Forward, 1.0f);
}

void UW_PantallaCarga::OcultarPantalla(TFunction<void()> AlFinalizar)
{
    if (DifuminadoSalida)
    {
        PlayAnimation(DifuminadoSalida, 0.f, 1);

     
        float Duracion = DifuminadoSalida->GetEndTime();
        GetWorld()->GetTimerManager().SetTimerForNextTick([this, Duracion, AlFinalizar]() {
            FTimerHandle TimerHandle;
            GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this, AlFinalizar]() {
                SetVisibility(ESlateVisibility::Hidden);
                if (Fondo_Carga) Fondo_Carga->SetVisibility(ESlateVisibility::Hidden);
                if (Image_Bomba) Image_Bomba->SetVisibility(ESlateVisibility::Hidden);
                AlFinalizar();
                }, Duracion, false);
            });
    }
    else
    {
        SetVisibility(ESlateVisibility::Hidden);
        if (AlFinalizar)
            AlFinalizar();
    }
}
