// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeLevel2.h"
#include "Bloque.h"
#include "Bloque_Ladrillo.h"
#include "Bloque_Acero.h"
#include "Bloque_Concreto.h"
#include "Bloque_Madera.h"
#include "BombermanCharacter.h" 
#include "Bomba.h"
#include "Dulce.h"
#include "Moneda.h"
#include "FabricaBloques.h"
#include "Enemigo_Subterraneo.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
 
AGameModeLevel2::AGameModeLevel2()
{
    PrimaryActorTick.bCanEverTick = true;
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
  
}

void AGameModeLevel2::BeginPlay()
{
    Super::BeginPlay();
    float Espaciado = 400.0f;
    FVector UbicacionInicial = FVector(-3994.488813, -3997.341838, -50.0f);
    Fabrica = GetWorld()->SpawnActor<AFabricaBloques>(AFabricaBloques::StaticClass());
    if (GetWorld())
    {
        for (int fila = 0; fila < Laberinto.Num(); fila++)
        {
            for (int columna = 0; columna < Laberinto[fila].Num(); columna++)
            {
                int32 valor = Laberinto[fila][columna];
                    FVector Posicion_Actual = UbicacionInicial + FVector(fila * Espaciado, columna * Espaciado, -50.0f);
                    FVector Posicion_Bomberman = UbicacionInicial + FVector(fila * Espaciado, columna * Espaciado, 220.0f);
                    ColocarBloque(valor, Posicion_Actual);
                    if (valor == 0) {
                        PuntoVacio.Add(Posicion_Bomberman);
                    }
                    if (valor == 6) {
                        PuntoContorno.Add(Posicion_Bomberman);
                    }
                    switch (valor) {
                    case 1:  NombreBloque = "Ladrillo"; break;
                    case 2: NombreBloque = "Concreto"; break;
                    case 3: NombreBloque = "Acero"; break;
                    case 4: NombreBloque = "Madera"; break;
                    case 5:  NombreBloque = "Ladrillo"; break;
                    default: NombreBloque = ""; break;
                     }
                    if (Fabrica) {
                        Fabrica->CrearBloque(NombreBloque, Posicion_Actual+(0.0f, 0.0f, 800.0f));
                    }
            }

        }
        StartPlayer();
        StartPlayer();
        StartPlayer();
        StartPlayer();
        //Spawn contorno
        for (int i = 0; i < 15; i++) {
            SpawnContorno();
        }
        
    }
    FTimerHandle Tiempo;
   // GetWorld()->GetTimerManager().SetTimer(Tiempo, this, &AGameModeLevel2::CambiarMaterial, 15.0f, false);
    MovRandom();
    AnalisisDatos();
    //ejercicio 7
    GetWorldTimerManager().SetTimer(TimerDulce, this, &AGameModeLevel2::NextDulce, 8.0f, true);
    //Ejercicio 8
   AMoneda* Moneda = GetWorld()->SpawnActor<AMoneda>(AMoneda::StaticClass(), FVector(0.0f, 0.0f, 1200.0f), FRotator(0.0f, 0.0f, 0.0f));
    if (Moneda)
    {
        Moneda->SetActorScale3D(FVector(6.0f, 6.0f, 0.5f));

    } 
    //AFabricaBloquesLevel2*fabrica=GetWorld()->SpawnActor<AFabricaBloquesLevel2>(AFabricaBloquesLevel2::StaticClass(), FVector(0.0f, 0.0f, 800.0f), FRotator(0.0f, 0.0f, 0.0f));
};
void AGameModeLevel2::ColocarBloque(int32 bloque, FVector Ubicacion) 
{
    ABloque* TipoBloque = nullptr;
    switch (bloque)
    {

    case 1:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Ladrillo>(ABloque_Ladrillo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 2:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Concreto>(ABloque_Concreto::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        ABloque_Concreto* Concreto = Cast<ABloque_Concreto>(TipoBloque);
        ListaBloques.Add(Concreto);
   
        break;
    }
    case 3:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Acero>(ABloque_Acero::StaticClass(), Ubicacion, FRotator::ZeroRotator);

        break;
    }
    case 4:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Madera>(ABloque_Madera::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        ABloque_Madera* Madera = Cast<ABloque_Madera>(TipoBloque);
        ListaBloques.Add(Madera);
        break;
    }
    case 5:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloque_Ladrillo>(ABloque_Ladrillo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        ABloque_Ladrillo* Ladrillo = Cast<ABloque_Ladrillo>(TipoBloque);
        ListaBloques.Add(Ladrillo);
        break;
    }
    default:
        break;
    }
    if (TipoBloque) {
        TipoBloque->SetActorScale3D(FVector(4.0f, 4.0f, 5.0f));
    }
}
void AGameModeLevel2::StartPlayer()
{
    float TamanoCelda = 400.f; // Tamaño de cada celda en tu grid
    FVector Offset = FVector(TamanoCelda / 2.0f, TamanoCelda / 2.0f, 0.0f);

    if (PuntoVacio.Num() > 0) 
    {
        int32 IndiceAleatorio = FMath::RandRange(0, PuntoVacio.Num() - 1);
        int32 IndiceAleatorio2 = FMath::RandRange(0, PuntoVacio.Num() - 1);
        FVector PosicionAleatoria = PuntoVacio[IndiceAleatorio] +Offset;
        FVector PosicionAleatoria2 = PuntoVacio[IndiceAleatorio2]+Offset;
      //  ABombermanCharacter* NuevoJugador = GetWorld()->SpawnActor<ABombermanCharacter>(ABombermanCharacter::StaticClass(), PosicionAleatoria, FRotator::ZeroRotator);
        ABomba*Bomba= GetWorld()->SpawnActor<ABomba>(ABomba::StaticClass(),FVector(0.0f,0.0f, -160.0f)+PosicionAleatoria2, FRotator::ZeroRotator);
        /*if (NuevoJugador)
        {
            NuevoJugador->SetActorScale3D(FVector(0.7f, 0.7f, 0.7f));
        }*/

    };
}

void AGameModeLevel2::SpawnContorno()
{
    float TamanoCelda = 400.f; // Tamaño de cada celda en tu grid
    FVector Offset = FVector(TamanoCelda / 2.0f, TamanoCelda / 2.0f, 0.0f);
    int32 IndiceAleatorio = FMath::RandRange(0, PuntoContorno.Num() - 1);
    FVector PosicionAleatoria = PuntoContorno[IndiceAleatorio] + Offset;
    ADulce* Dulce = GetWorld()->SpawnActor<ADulce>(ADulce::StaticClass(), PosicionAleatoria, FRotator::ZeroRotator);
     if (Dulce) {
         Dulce->SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
        }
}

void AGameModeLevel2::CambiarMaterial()
{
    for (ABloque* BloqueIter : ListaBloques) 
    {
  
            if (!BloqueIter) continue;

            if (ABloque_Ladrillo* Ladrillo = Cast<ABloque_Ladrillo>(BloqueIter))
            {
                if (Ladrillo->Mesh && Ladrillo->Material3)
                    Ladrillo->Mesh->SetMaterial(0, Ladrillo->Material3);
            }

            else if (ABloque_Concreto* Concreto = Cast<ABloque_Concreto>(BloqueIter))
            {
                if (Concreto->Mesh && Concreto->Material)
                    Concreto->Mesh->SetMaterial(0, Concreto->Material);
            }

            else if (ABloque_Madera* Madera = Cast<ABloque_Madera>(BloqueIter))
            {
                if (Madera->Mesh && Madera->Material2)
                    Madera->Mesh->SetMaterial(0, Madera->Material2);
        
             }

    }

}

void AGameModeLevel2::MovRandom()
{
    for (int i = 0; i < 5; i++) {
        int aleatorio = FMath::RandRange(0, ListaBloques.Num()-1);
        ABloque* BloqueMov = ListaBloques[aleatorio];
        if (!BloqueMov->Encendido || !BloqueMov->Funcion)
        {
            BloqueMov->Encendido = true;
            int opcion = FMath::RandRange(0, 1);
            BloqueMov->Funcion = [BloqueMov, opcion](float DeltaTime)
            {

                if (opcion == 0) {
                        BloqueMov->MovHorizontal(DeltaTime);
                }
                else if (opcion == 1) {
                        BloqueMov->MovVertical(DeltaTime);
                }
            };
            UE_LOG(LogTemp, Warning, TEXT("Bloque activado: %s"), *BloqueMov->GetName());
        }
    }

}
void AGameModeLevel2::NextDulce()
{
   /* int TamanoCelda = 400;
    FVector Offset = FVector(TamanoCelda / 2.0f, TamanoCelda / 2.0f, 0.0f);
    if (NroPosicion >= NroPosicionMax) {
        return;
    }
    if (pDulce ) 
    {
            
     pDulce->Destroy();
            
    }
     int32 IndiceAleatorio = FMath::RandRange(0, PuntoVacio.Num() - 1);
     FVector PosicionRandom = PuntoVacio[IndiceAleatorio]+ Offset;
     pDulce = GetWorld()->SpawnActor<ADulce>(ADulce::StaticClass(), FVector(0.0f, 0.0f, -160.0f) + PosicionRandom, FRotator::ZeroRotator);
     NroPosicion++;
     */
}

void AGameModeLevel2::AnalisisDatos()
{
    FString Resultado = TEXT("ANALISIS DEL LABERINTO\n");
    float Ocupacion = (ListaBloques.Num() / 4000.0f) * 1000.0f; //PORCEBTAJE DE BLOQUES 
    UE_LOG(LogTemp, Warning, TEXT("Bloque activado: %d"),ListaBloques.Num());
    Resultado += FString::Printf(TEXT("Porcentaje:  %.2f%%\n"), Ocupacion);
    //Bloques por tipo
    int32 CantidadLadrillo = 0;
    int32 CantidadConcreto = 0;
    int32 CantidadMadera = 0;
    int32 CantidadAcero = 0;
    for (ABloque* pBloque : ListaBloques) {
        if (Cast<ABloque_Ladrillo>(pBloque)) CantidadLadrillo++;
        else if (Cast<ABloque_Concreto>(pBloque)) CantidadConcreto++;
        else if (Cast<ABloque_Madera>(pBloque)) CantidadMadera++;
        else if (Cast<ABloque_Acero>(pBloque)) CantidadAcero++;
    }


        FString ResultadoTipos = TEXT("Tipo de laberinto\n");
        ResultadoTipos += FString::Printf(TEXT("Cantidad De Ladrillo: %d"), CantidadLadrillo );
    GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, Resultado);
    
}



