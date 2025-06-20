// Fill out your copyright notice in the Description page of Project Settings.


#include "W_MenuConfiguracion.h"
#include "HUD_Bomberman.h"
#include "Kismet/GameplayStatics.h"



void UW_MenuConfiguracion::NativeConstruct()
{
    if (Button_Volver)
    {
        Button_Volver->OnClicked.AddDynamic(this, &UW_MenuConfiguracion::SalirAlMenu);
    }
}

void UW_MenuConfiguracion::SalirAlMenu()
{
    AHUD_Bomberman* HUD = Cast<AHUD_Bomberman>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
    if (HUD)
    {
        HUD->MostrarMenuPrincipal();
        RemoveFromParent();
    }
}
