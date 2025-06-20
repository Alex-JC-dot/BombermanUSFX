// Fill out your copyright notice in the Description page of Project Settings.


#include "W_MenuPrincipal.h"
#include "HUD_Bomberman.h"
#include "Kismet/GameplayStatics.h"


void UW_MenuPrincipal::NativeConstruct()
{
    if (Button_Historia)
    {
        Button_Historia->OnClicked.AddDynamic(this, &UW_MenuPrincipal::SeleccionarDificultad);
    }

    if (Button_Opciones)
    {
        Button_Opciones->OnClicked.AddDynamic(this, &UW_MenuPrincipal::Opciones);
    }

    if (Button_Salir)
    {
        Button_Salir->OnClicked.AddDynamic(this, &UW_MenuPrincipal::Salir);
    }
    if (Button_QR)
    {
        Button_QR->OnClicked.AddDynamic(this, &UW_MenuPrincipal::MostrarQR);
    }

}

void UW_MenuPrincipal::SeleccionarDificultad()
{
    AHUD_Bomberman* HUD = Cast<AHUD_Bomberman>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
    if (HUD)
    {
        HUD->MostrarSeleccionDificultad();
        RemoveFromParent(); 
    }
}

void UW_MenuPrincipal::Opciones()
{

    AHUD_Bomberman* HUD = Cast<AHUD_Bomberman>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
    if (HUD)
    {
        HUD->MostrarPantallaOpciones();
        RemoveFromParent();
    }

}

void UW_MenuPrincipal::Salir()
{
    UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, true);

}

void UW_MenuPrincipal::MostrarQR()
{
    AHUD_Bomberman* HUD = Cast<AHUD_Bomberman>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
    if (HUD)
    {
        HUD->MostraQr();
        RemoveFromParent();
    }
}
