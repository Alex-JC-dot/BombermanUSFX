// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "W_QR.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UW_QR : public UUserWidget
{
	GENERATED_BODY()
	virtual void NativeConstruct() override;


public:

	void VolverMenu();


	UPROPERTY(meta = (BindWidget))
	class UButton* Button_Volver;

};
