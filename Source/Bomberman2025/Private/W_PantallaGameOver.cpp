// Fill out your copyright notice in the Description page of Project Settings.


#include "W_PantallaGameOver.h"
#include "Kismet/GameplayStatics.h"


void UW_PantallaGameOver::NativeConstruct()
{
    if (Button_Reiniciar)
    {
        Button_Reiniciar->OnClicked.AddDynamic(this, &UW_PantallaGameOver::OnReintentarClicked);
    }

    if (Button_SalirMenu)
    {
        Button_SalirMenu->OnClicked.AddDynamic(this, &UW_PantallaGameOver::OnVolverAlMenuClicked);
    }

}

void UW_PantallaGameOver::OnReintentarClicked()
{

	FName NombreNivel = *UGameplayStatics::GetCurrentLevelName(this, true);
	UGameplayStatics::OpenLevel(this, NombreNivel);

}

void UW_PantallaGameOver::OnVolverAlMenuClicked()
{
	UGameplayStatics::OpenLevel(this, "IntroLevel");
}

