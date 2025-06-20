// Fill out your copyright notice in the Description page of Project Settings.


#include "Comportamiento_Perseguir.h"
#include "EnemigoBase.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

void UComportamiento_Perseguir::EjecutarComportamiento(AEnemigoBase* Enemigo)
{
    if (!Enemigo) return;

    // Velocidad de persecución (más rápida)
    Enemigo->GetCharacterMovement()->MaxWalkSpeed = 300.f;

    AActor* Jugador = Enemigo->ObtenerJugador();
    if (!Jugador) return;

    float DistanciaAlJugador = FVector::Dist(Enemigo->GetActorLocation(), Jugador->GetActorLocation());

    // Si el jugador está lejos, volver a patrullar
    if (DistanciaAlJugador > 1000.f)  // Puedes ajustar este valor
    {
        Enemigo->CambiarComportamiento(EComportamiento::Patrullar);
        return;
    }

    // Mover hacia el jugador
    AAIController* AIController = Cast<AAIController>(Enemigo->GetController());
    if (AIController)
    {
        AIController->MoveToActor(Jugador);

        // Girar hacia el jugador
        FVector Direccion = Jugador->GetActorLocation() - Enemigo->GetActorLocation();
        FRotator NuevaRotacion = UKismetMathLibrary::MakeRotFromX(Direccion);
        Enemigo->SetActorRotation(FRotator(0.f, NuevaRotacion.Yaw, 0.f));
    }
}
