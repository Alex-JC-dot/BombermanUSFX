// Fill out your copyright notice in the Description page of Project Settings.


#include "W_Dificultad.h"
#include "GestorDificultad_Facade.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "TimerManager.h"
#include "HUD_Bomberman.h"
#include "Components/VerticalBox.h"

void UW_Dificultad::NativeConstruct()
{
    Super::NativeConstruct();

    TArray<AActor*> Encontrados;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGestorDificultad_Facade::StaticClass(), Encontrados);

    if (Encontrados.Num() > 0)
    {
        GestorDificultad = Cast<AGestorDificultad_Facade>(Encontrados[0]);
       
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("No se encontró el Gestor de Dificultad"));
    }

    if (IsValid(Button_1))
    {
        
        Button_1->OnClicked.AddDynamic(this, &UW_Dificultad::SeleccionarFacil);
      
    }

    if (IsValid(Button_2))
    {
       
        Button_2->OnClicked.AddDynamic(this, &UW_Dificultad::SeleccionarMedio);
    }

    if (IsValid(Button_3))
    {
 
        Button_3->OnClicked.AddDynamic(this, &UW_Dificultad::SeleccionarDificil);
       
    }
    //Botones de Nivel
    if (IsValid(Button_Nivel1))
    {
    
        Button_Nivel1->OnClicked.AddDynamic(this, &UW_Dificultad::SeleccionarNivel1);

    }
    if (IsValid(Button_Volver))
    {

        Button_Volver->OnClicked.AddDynamic(this, &UW_Dificultad::RegresarAlMenu);

    }

}
void UW_Dificultad::SeleccionarFacil()
{
    UGameInstance_Datos* GameInstance = Cast<UGameInstance_Datos>(GetGameInstance());
    if (GameInstance)
    {
        GameInstance->EstablecerDificultadInt(1);
      
    }

    if (GestorDificultad)
        GestorDificultad->ConfigurarNivel(1);
    else
        GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("GestorDificultad es nulo"));

    SeleccionarNivel1();
}

void UW_Dificultad::SeleccionarMedio()
{
    UGameInstance_Datos* GameInstance = Cast<UGameInstance_Datos>(GetGameInstance());
    if (GameInstance)
    {
        GameInstance->EstablecerDificultadInt(2);
     
    }

    if (GestorDificultad)
        GestorDificultad->ConfigurarNivel(2);
    else
        GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("GestorDificultad es nulo"));

    SeleccionarNivel1();
}

void UW_Dificultad::SeleccionarDificil()
{
    UGameInstance_Datos* GameInstance = Cast<UGameInstance_Datos>(GetGameInstance());
    if (GameInstance)
    {
        GameInstance->EstablecerDificultadInt(3);
   
    }

    if (GestorDificultad)
        GestorDificultad->ConfigurarNivel(3);
    else
        GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("GestorDificultad es nulo"));

    SeleccionarNivel1();
}


void UW_Dificultad::SeleccionarNivel1()
{
    ReproducirCarga("NivelAntiguo");
}

void UW_Dificultad::RegresarAlMenu()
{
    AHUD_Bomberman* HUD = Cast<AHUD_Bomberman>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
    if (HUD)
    {
        HUD->MostrarMenuPrincipal();
        RemoveFromParent();
    }
}

void UW_Dificultad::ReproducirCarga(FName NombreNivel)
{
    if (CuadroCarga && BombaGiro) {
        FondoCarga->SetVisibility(ESlateVisibility::Visible);
        ImageBomba->SetVisibility(ESlateVisibility::Visible);

        PlayAnimation(CuadroCarga);
        PlayAnimation(BombaGiro, 0.f, 0, EUMGSequencePlayMode::Forward, 1.0f);
        float Duracion = CuadroCarga->GetEndTime();
        FTimerHandle TimerHandle;
        APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
        if (PC)
        {
            PC->bShowMouseCursor = false;
            PC->SetInputMode(FInputModeGameOnly());
        }
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this, NombreNivel]() {UGameplayStatics::OpenLevel(this, NombreNivel); }, Duracion+5.0F, false);
    }
}
