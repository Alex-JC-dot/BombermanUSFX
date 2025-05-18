// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget_1.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN2025_API UMyUserWidget_1 : public UUserWidget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	void SetName();

protected:
	 virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* PlayerInputBox;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* PlayerName;
};

