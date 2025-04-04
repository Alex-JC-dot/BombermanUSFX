#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeLevel1.generated.h"

UCLASS()
class BOMBERMAN2025_API AGameModeLevel1 : public AGameModeBase
{
    GENERATED_BODY()

public:
    AGameModeLevel1();

protected:
    virtual void BeginPlay() override;

private:
    void GenerarLaberinto();

    UPROPERTY(EditDefaultsOnly, Category = "Configuración")
    TSubclassOf<class AMuro1> ClaseMuro1;

    static constexpr int filas = 20;
    static constexpr int columnas = 20;

    int MapaLaberinto[filas][columnas];
};
