// Fill out your copyright notice in the Description page of Project Settings.

#include "HUD_Bomberman.h"
#include "Blueprint/UserWidget.h"
#include "W_PantallaCarga.h"
#include "W_Dificultad.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"


AHUD_Bomberman::AHUD_Bomberman()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/GameModeCasero/UI/UI_Wideget"));
    if (MenuBPClass.Succeeded())
    {
        MenuPrincipal = MenuBPClass.Class;
    }
    static ConstructorHelpers::FClassFinder<UUserWidget> PantallaCaegaBP(TEXT("/Game/GameModeCasero/UI/W_PantallaCarga"));
    if (PantallaCaegaBP.Succeeded())
    {
        PantallaCarga = PantallaCaegaBP.Class;
    }
    static ConstructorHelpers::FClassFinder<UUserWidget> DificultadBPClass(TEXT("/Game/GameModeCasero/UI/W_Menu"));
    if (DificultadBPClass.Succeeded())
    {
        PantallaSeleccionDificultad = DificultadBPClass.Class;
    }

    static ConstructorHelpers::FClassFinder<UUserWidget> GameOverBPClass(TEXT("/Game/GameModeCasero/UI/W_PantallaGameOver"));
    if (GameOverBPClass.Succeeded())
    {
        PantallaGameOver = GameOverBPClass.Class;
    }

    static ConstructorHelpers::FClassFinder<UUserWidget> BarraVidaJefeBPClass(TEXT("/Game/GameModeCasero/UI/W_BarraFinalBooss"));
    if (BarraVidaJefeBPClass.Succeeded())
    {
        BarraVidaJefeClass = BarraVidaJefeBPClass.Class;
    }

    static ConstructorHelpers::FClassFinder<UUserWidget> MenuOpcionesBPClass(TEXT("/Game/GameModeCasero/UI/W_MenuOpciones"));
    if (MenuOpcionesBPClass.Succeeded())
    {
        WidgetOpcionesClass = MenuOpcionesBPClass.Class;
    }
    static ConstructorHelpers::FClassFinder<UUserWidget> QrBPClass(TEXT("/Game/GameModeCasero/UI/WB_Qr"));
    if (QrBPClass.Succeeded())
    {
        WidgetQRClass = QrBPClass.Class;
    }

}
void AHUD_Bomberman::BeginPlay()
{
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC)
    {
      
        PC->bShowMouseCursor = false;
        PC->bEnableClickEvents = false;
        PC->bEnableMouseOverEvents = false;

        FInputModeGameOnly InputMode;
        PC->SetInputMode(InputMode);
    }
    FString NombreNivel = GetWorld()->GetMapName();

    NombreNivel.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);

    if (NombreNivel == "IntroLevel")
    {
        MostrarMenuPrincipal();
    }
}

void AHUD_Bomberman::MostrarMenuPrincipal()
{
    if (PantallaSeleccionDificultad)
    {
        WidgetMenuPrincipal = CreateWidget<UW_MenuPrincipal>(GetWorld(), PantallaSeleccionDificultad);
        if (WidgetMenuPrincipal)
        {
            WidgetMenuPrincipal->AddToViewport();

            APlayerController* PC = GetWorld()->GetFirstPlayerController();
            if (PC)
            {
                PC->bShowMouseCursor = true;

                FInputModeUIOnly InputMode;
                InputMode.SetWidgetToFocus(WidgetMenuPrincipal->TakeWidget());
                InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
                PC->SetInputMode(InputMode);
            }
        }

    }
}

void AHUD_Bomberman::MostrarPantallaCarga()
{

    if (!WidgetPantallaCarga)
    {
        WidgetPantallaCarga = CreateWidget<UW_PantallaCarga>(GetWorld(), PantallaCarga);
        if (WidgetPantallaCarga)
        {
            WidgetPantallaCarga->AddToViewport(100);
            WidgetPantallaCarga->MostrarPantalla();
        }

    }
}

void AHUD_Bomberman::OcultarPantallaCarga(TFunction<void()> AlFinalizar)
{

    if (WidgetPantallaCarga)
    {
        WidgetPantallaCarga->OcultarPantalla(AlFinalizar);
    }

}


void AHUD_Bomberman::MostrarSeleccionDificultad()
{
    if (MenuPrincipal)
    {
        WidgetDificultad = CreateWidget<UW_Dificultad>(GetWorld(), MenuPrincipal);
        if (WidgetDificultad)
        {
            WidgetDificultad->AddToViewport();

            APlayerController* PC = GetWorld()->GetFirstPlayerController();
            if (PC)
            {
                PC->bShowMouseCursor = true;
                PC->bEnableClickEvents = true;
                PC->bEnableMouseOverEvents = true;

                FInputModeUIOnly InputMode;
                InputMode.SetWidgetToFocus(WidgetDificultad->TakeWidget());
                InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
                PC->SetInputMode(InputMode);
            }
        }
    }

}

void AHUD_Bomberman::MostrarPantallaGameOver()
{
    

    if (PantallaGameOver)
    {
        WidgetPantallaGameOver = CreateWidget<UW_PantallaGameOver>(GetWorld(), PantallaGameOver);
        if (WidgetPantallaGameOver)
        {
            
            WidgetPantallaGameOver->AddToViewport();

            APlayerController* PC = GetWorld()->GetFirstPlayerController();
            if (PC)
            {
                PC->bShowMouseCursor = true;
                PC->bEnableClickEvents = true;
                PC->bEnableMouseOverEvents = true;

                FInputModeUIOnly InputMode;
                InputMode.SetWidgetToFocus(WidgetPantallaGameOver->TakeWidget()); 
                InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
                PC->SetInputMode(InputMode);
            }
        }

    }
   

}
void AHUD_Bomberman::MostrarBarraVidaJefe()
{
  
    if (BarraVidaJefeClass)
    {
        WidgetBarraVidaJefe = CreateWidget<UW_BarraVidaEnemigo>(GetWorld(), BarraVidaJefeClass);
        if (WidgetBarraVidaJefe)
        {
           ;
            WidgetBarraVidaJefe->AddToViewport();
        
        }
        else
        {
            GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Error al crear el widget de barra del jefe"));
        }
    }
}

void AHUD_Bomberman::OcultarBarraVidaJefe()
{
    if (WidgetBarraVidaJefe)
    {
        WidgetBarraVidaJefe->RemoveFromParent();
        WidgetBarraVidaJefe = nullptr;
    }
}

void AHUD_Bomberman::MostrarPantallaOpciones()
{
    if (WidgetOpcionesClass)
    {
        WidgetMenuopciones = CreateWidget<UW_MenuConfiguracion>(GetWorld(), WidgetOpcionesClass);
        if (WidgetMenuopciones)
        {
            WidgetMenuopciones->AddToViewport();

            APlayerController* PC = GetWorld()->GetFirstPlayerController();
            if (PC)
            {
                PC->bShowMouseCursor = true;
                PC->bEnableClickEvents = true;
                PC->bEnableMouseOverEvents = true;

                FInputModeUIOnly InputMode;
                InputMode.SetWidgetToFocus(WidgetMenuopciones->TakeWidget()); // <- CORRECTO
                InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
                PC->SetInputMode(InputMode);
            }
        }
    }
}

void AHUD_Bomberman::MostraQr()
{
    if (WidgetQRClass)
    {
        WidgetQr = CreateWidget<UW_QR>(GetWorld(), WidgetQRClass);
        if (WidgetQr)
        {
            WidgetQr->AddToViewport();

            APlayerController* PC = GetWorld()->GetFirstPlayerController();
            if (PC)
            {
                PC->bShowMouseCursor = true;
                PC->bEnableClickEvents = true;
                PC->bEnableMouseOverEvents = true;

                FInputModeUIOnly InputMode;
                InputMode.SetWidgetToFocus(WidgetMenuopciones->TakeWidget()); // <- CORRECTO
                InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
                PC->SetInputMode(InputMode);
            }
        }
    }

}
