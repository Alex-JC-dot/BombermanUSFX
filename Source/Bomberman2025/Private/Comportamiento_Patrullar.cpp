// Fill out your copyright notice in the Description page of Project Settings.


#include "Comportamiento_Patrullar.h"
#include "EnemigoBase.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

void UComportamiento_Patrullar::EjecutarComportamiento(AEnemigoBase* Enemigo)
{
    if (!Enemigo) return;

    Enemigo->GetCharacterMovement()->MaxWalkSpeed = 300.f;

    VerificarSiEstaAtascado(Enemigo);

    if (!bTieneDestino || FVector::Dist(Enemigo->GetActorLocation(), DestinoActual) < 50.f)
    {
        GenerarDestinoValido(Enemigo);
    }

    AAIController* AIController = Cast<AAIController>(Enemigo->GetController());
    if (AIController && bTieneDestino)
    {
        AIController->MoveToLocation(DestinoActual);

        FVector Direccion = DestinoActual - Enemigo->GetActorLocation();
        FRotator NuevaRotacion = UKismetMathLibrary::MakeRotFromX(Direccion);
        Enemigo->SetActorRotation(FRotator(0.f, NuevaRotacion.Yaw, 0.f));
    }

    AActor* Jugador = Enemigo->ObtenerJugador();
    if (Jugador && FVector::Dist(Enemigo->GetActorLocation(), Jugador->GetActorLocation()) < 600.f)
    {
        Enemigo->CambiarComportamiento(EComportamiento::Perseguir);
    }
}

void UComportamiento_Patrullar::GenerarDestinoValido(AEnemigoBase* Enemigo)
{
    UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
    if (!NavSys) return;

    for (int i = 0; i < 10; i++) // Intentar hasta 10 veces encontrar un destino válido
    {
        FNavLocation PuntoAleatorio;
        if (NavSys->GetRandomPointInNavigableRadius(Enemigo->GetActorLocation(), 1000.f, PuntoAleatorio))
        {
            // Verificar si hay un camino real hasta ese punto
            UNavigationPath* Path = NavSys->FindPathToLocationSynchronously(GetWorld(), Enemigo->GetActorLocation(), PuntoAleatorio.Location);
            if (Path && Path->IsValid() && Path->PathPoints.Num() > 1)
            {
                DestinoActual = PuntoAleatorio.Location;
                bTieneDestino = true;
                return;
            }
        }
    }

    // Si después de 10 intentos no encuentra, se queda quieto
    bTieneDestino = false;
}

void UComportamiento_Patrullar::VerificarSiEstaAtascado(AEnemigoBase* Enemigo)
{
    if (!Enemigo) return;

    float Distancia = FVector::Dist(Enemigo->GetActorLocation(), UltimaPosicion);

    if (Distancia > 50.f)
    {
        TiempoSinMoverse = 0.f;
        UltimaPosicion = Enemigo->GetActorLocation();
    }
    else
    {
        float DeltaTime = 0.f;
        if (Enemigo->GetWorld())
        {
            DeltaTime = Enemigo->GetWorld()->GetDeltaSeconds();
        }

        TiempoSinMoverse += DeltaTime;

        if (TiempoSinMoverse > 4.f)
        {
            bTieneDestino = false;
            TiempoSinMoverse = 0.f;
            UltimaPosicion = Enemigo->GetActorLocation();
        }
    }
}

void UComportamiento_Patrullar::ForzarNuevoDestino()
{
    bTieneDestino = false;
}
