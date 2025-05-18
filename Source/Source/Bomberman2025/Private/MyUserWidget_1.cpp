// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget_1.h"
#include "MyGameInstance.h"

void UMyUserWidget_1::NativeConstruct()
{
	Super::NativeConstruct();
	if (PlayerName) {
		
		PlayerName->SetText(FText::FromString("none"));
	}
}

void UMyUserWidget_1::SetName( )
{
	if (PlayerInputBox) {
		const FString Nombre = PlayerInputBox->GetText().ToString();

		if (PlayerName) {
			PlayerName->SetText(FText::FromString(Nombre));
		}

		if (UGameInstance* GI = GetGameInstance())
		{
			if (UMyGameInstance* MI = Cast<UMyGameInstance>(GI))
			{
				MI->NombreJugador(Nombre);
			}
		}

	}
}



