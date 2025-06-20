// Fill out your copyright notice in the Description page of Project Settings.


#include "GestorEnemigos.h"
#include "EnemigoBase.h"
#include "PuertaNiveles.h"
#include "PuertaNiveles_PuertaHielo.h"
#include "PuertaNiveles_PuertaCementerio.h"
#include "PuertaNiveles_PuertaAntigua.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AGestorEnemigos::AGestorEnemigos()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    EnemigosVivos = 0;
    ClasePuerta = nullptr;
    TransformPuerta =FTransform(FRotator(0.0f, 90.0f, 0.0f));
}

// Called when the game starts or when spawned
void AGestorEnemigos::BeginPlay()
{
	Super::BeginPlay();
    GetWorldTimerManager().SetTimer(
        TimerHandle_Conteo,
        this,
        &AGestorEnemigos::ContarEnemigos,
        1.0f,
        false
    );
}

// Called every frame
void AGestorEnemigos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AGestorEnemigos::ContarEnemigos()
{
    TArray<AActor*> Enemigos;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemigoBase::StaticClass(), Enemigos);

    EnemigosVivos = Enemigos.Num();

    for (AActor* Actor : Enemigos)
    {
        AEnemigoBase* Enemigo = Cast<AEnemigoBase>(Actor);
        if (Enemigo)
        {
            Enemigo->AsignarGestor(this);
        }
    }
}

void AGestorEnemigos::NotificarMuerte()
{
    EnemigosVivos--;
  /*  GEngine->AddOnScreenDebugMessage(-1,10.f,FColor::Cyan,FString::Printf(TEXT("NotificarMuerte llamado. Enemigos restantes: %d"), EnemigosVivos));*/
    
    if (EnemigosVivos <= 0)
    {
        GenerarPuerta();
    }
}

void AGestorEnemigos::EstablecerBuilder(TScriptInterface<IIBuilderEscenario> Builder)
{
    if (!Builder)
    {
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Builder es nullptr"));
        return;
    }

    BuilderActual = Builder;
}


void AGestorEnemigos::GenerarPuerta()
{




    FTransform TransformModificado = TransformPuerta;
    FVector NuevaUbicacion = TransformPuerta.GetLocation() + FVector(-3394.488813, 3252.658162, -70.0f);
    TransformModificado.SetLocation(NuevaUbicacion);

    if (BuilderActual)
    {
        ClasePuerta = BuilderActual->ObtenerClasePuerta();
    }

    if (ClasePuerta)
    {
        GetWorld()->SpawnActor<APuertaNiveles>(ClasePuerta, TransformModificado);
      /*  GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, TEXT("Puerta generada correctamente"));*/
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("ERROR: ClasePuerta no está asignada."));
    }
    if (BuilderActual)
    {
        ClasePuerta = BuilderActual->ObtenerClasePuerta();
        if (!ClasePuerta)
        {
            GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("BuilderActual devolvió nullptr para ClasePuerta"));
        }
        else
        {
          /*  GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, FString::Printf(TEXT("ClasePuerta válida: %s"), *ClasePuerta->GetName()));*/
        }
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("BuilderActual es nullptr"));
    }
}
