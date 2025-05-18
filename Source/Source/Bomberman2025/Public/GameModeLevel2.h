#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Bloque.h"
#include "Bloque_Ladrillo.h"
#include "Bloque_Concreto.h"
#include "Bloque_Madera.h"
#include "Bloque_Acero.h"
#include "Dulce.h"
#include "Moneda.h"
#include"FabricaBloques.h"
#include "GameModeLevel2.generated.h"

// Ensure GENERATED_BODY is not inside any conditional preprocessor block
UCLASS()
class BOMBERMAN2025_API AGameModeLevel2 : public AGameModeBase
{
    GENERATED_BODY()
public:
    AGameModeLevel2();

protected:
    virtual void BeginPlay() override;

    TArray<TArray<int32>> Laberinto =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,6,2,6,6,6,2,6,2,6,6,6,5,6,6,6,5,6,6,1},
        {1,6,2,2,2,0,2,0,2,2,5,0,5,5,5,0,5,5,6,1},
        {1,6,0,0,2,0,0,0,0,0,5,0,0,0,5,0,0,0,6,1},
        {1,2,2,0,2,2,2,2,2,0,5,5,5,0,5,5,5,5,6,1},
        {1,6,0,0,0,0,0,0,2,0,0,0,5,0,0,0,0,0,6,1},
        {1,6,2,2,2,2,2,0,2,2,5,0,5,5,5,5,5,5,6,1},
        {1,6,2,0,0,0,2,0,0,0,5,0,0,0,5,0,0,5,6,1},
        {1,6,2,0,2,2,2,2,2,0,5,5,5,0,5,5,0,5,6,1},
        {1,6,0,0,2,0,0,0,0,2,0,0,1,0,0,0,0,0,6,1},
        {1,3,3,0,3,3,3,0,3,3,4,0,4,4,4,0,4,4,4,1},
        {1,6,0,0,0,0,3,0,0,0,4,0,0,0,4,0,0,0,6,1},
        {1,6,3,3,3,0,3,3,3,0,4,4,4,0,4,4,4,4,6,1},
        {1,6,3,0,0,0,0,0,3,0,0,0,4,0,0,0,0,0,6,1},
        {1,6,3,0,3,3,3,0,3,4,4,0,4,4,4,4,4,4,6,1},
        {1,6,0,0,3,0,0,0,0,0,4,0,0,0,0,0,0,4,6,1},
        {1,3,3,0,3,0,3,3,3,0,4,4,4,4,4,4,0,4,6,1},
        {1,6,0,0,0,0,3,0,0,0,0,0,0,0,0,4,0,0,6,1},
        {1,6,3,3,3,3,3,6,3,3,4,4,4,4,0,4,4,4,6,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    ABloque* Bloque = nullptr;

protected:
    void ColocarBloque(int32 valor, FVector Ubicacion);
    void StartPlayer();

public:
    TArray<FVector> PuntoVacio;
    TArray<FVector> PuntoContorno;
    void SpawnContorno();

    TArray<ABloque*> ListaBloques;
    void CambiarMaterial();

    void MovRandom();

    void NextDulce();
    int NroPosicion = 0;
    int NroPosicionMax = 4;
    ADulce* pDulce;
    FTimerHandle TimerDulce;

    void AnalisisDatos();

    FTimerHandle TiempoMoneda;
    // Factory Method 
    AFabricaBloques * Fabrica; // codigo que cree
    FString NombreBloque;
};