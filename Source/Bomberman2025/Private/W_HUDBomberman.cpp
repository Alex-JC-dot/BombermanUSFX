// Fill out your copyright notice in the Description page of Project Settings.


#include "W_HUDBomberman.h"
#include "Kismet/GameplayStatics.h"
#include "EnemigoBase.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"





void UW_HUDBomberman::ActualizarBombas(int Bombas)
{
	if (!TextBlock_Bomba)
	{
		
		GEngine->AddOnScreenDebugMessage(-1,10, FColor::Green, TEXT("TextBlock_Bomba no está enlazado."));
		return;

	}
	FString TextoFinal = FString::Printf(TEXT("x %d"), Bombas);
	TextBlock_Bomba->SetText(FText::FromString(TextoFinal));
}

void UW_HUDBomberman::ActualizarVida(float Porcentaje)
{
	if (ProgressBar_0)
	{
		ProgressBar_0->SetPercent(Porcentaje);
	}
}





