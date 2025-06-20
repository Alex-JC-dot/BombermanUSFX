// Fill out your copyright notice in the Description page of Project Settings.


#include "Comportamiento_Escapar.h"
//#include "EnemigoBase.h"
//#include "AIController.h"
//#include "NavigationSystem.h"
//#include "GameFramework/CharacterMovementComponent.h"
//
//void UComportamiento_Escapar::EjecutarComportamiento(AEnemigoBase* Enemigo)
//{
//
//    if (!Enemigo) return;
//
//    // Verificar que se tiene una posición válida de bomba
//    if (Enemigo->UltimaPosicionBomba.IsNearlyZero())
//    {
//        UE_LOG(LogTemp, Warning, TEXT("Enemigo: UltimaPosicionBomba no está seteada."));
//        return;
//    }
//
//    AAIController* AIController = Cast<AAIController>(Enemigo->GetController());
//    if (!AIController) return;
//
//    // Calcular la dirección contraria a la bomba
//    FVector DireccionEscape = Enemigo->GetActorLocation() - Enemigo->UltimaPosicionBomba;
//    DireccionEscape.Normalize();
//
//    // Crear un destino alejado en esa dirección
//    FVector DestinoDeseado = Enemigo->GetActorLocation() + DireccionEscape * 800.f;
//
//    // Validar que el destino esté dentro del NavMesh
//    UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(Enemigo->GetWorld());
//    FNavLocation DestinoValido;
//
//    if (NavSys && NavSys->ProjectPointToNavigation(DestinoDeseado, DestinoValido))
//    {
//        // Mover al enemigo al destino válido
//        AIController->MoveToLocation(DestinoValido.Location);
//
//        // Rotar el enemigo hacia la dirección de escape
//        FRotator NuevaRotacion = DireccionEscape.Rotation();
//        Enemigo->SetActorRotation(NuevaRotacion);
//
//        // Ajustar velocidad de escape
//        Enemigo->GetCharacterMovement()->MaxWalkSpeed = 350.f;
//
//        UE_LOG(LogTemp, Log, TEXT("Enemigo escapando a %s"), *DestinoValido.Location.ToString());
//    }
//    else
//    {
//        UE_LOG(LogTemp, Warning, TEXT("Destino de escape no es válido en el NavMesh"));
//    }
//}
