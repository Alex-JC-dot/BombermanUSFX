#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Border.h"
#include "GestorDificultad_Facade.h"
#include "GameInstance_Datos.h"
#include "Animation/WidgetAnimation.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"
#include "W_Dificultad.generated.h"


UCLASS()
class BOMBERMAN2025_API UW_Dificultad : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

   
    UFUNCTION()
    void SeleccionarFacil();

    UFUNCTION()
    void SeleccionarMedio();

    UFUNCTION()
    void SeleccionarDificil();

    
    UFUNCTION()
    void SeleccionarNivel1();

    UFUNCTION()
    void RegresarAlMenu();

    UFUNCTION()
    void ReproducirCarga(FName NombreNIvel);

protected:
    //Botones de Dificultad y otros
    UPROPERTY(meta = (BindWidget))
    class UButton* Button_1;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_2;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_3;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Nivel1;
    UPROPERTY(meta = (BindWidget))
    class UBorder* FondoCarga;

    UPROPERTY(meta = (BindWidget))
    class UImage* ImageBomba;

    AGestorDificultad_Facade* GestorDificultad;
    //Contenedor que gurarda el SubMenu Dificultades
    UPROPERTY(meta = (BindWidget))
    UVerticalBox* ContenedorDificultad;

    //Contenedor que guarda un submenu Niveles
    
    UPROPERTY(meta = (BindWidget))
    UVerticalBox* ContenedorNiveles;
    
    //Animaciones
    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* CuadroCarga;

    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* BombaGiro;

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Volver;

    //Logica aparte
    int Nivel= 0;

};