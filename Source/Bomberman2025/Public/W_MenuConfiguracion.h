// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "W_MenuConfiguracion.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UW_MenuConfiguracion : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

public:

	UFUNCTION()
	void SalirAlMenu();


	UPROPERTY(meta = (BindWidget))
	class UButton* Button_Volver;
	
};
