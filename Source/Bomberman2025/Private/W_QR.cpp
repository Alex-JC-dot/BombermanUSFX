// Fill out your copyright notice in the Description page of Project Settings.


#include "W_QR.h"
#include "HUD_Bomberman.h"
#include "Kismet/GameplayStatics.h"


void UW_QR::NativeConstruct()
{
    if (IsValid(Button_Volver))
    {

        Button_Volver->OnClicked.AddDynamic(this, &UW_QR::VolverMenu);

    }

}

void UW_QR::VolverMenu()
{
    AHUD_Bomberman* HUD = Cast<AHUD_Bomberman>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
    if (HUD)
    {
        HUD->MostrarMenuPrincipal();
        RemoveFromParent();
    }

}
