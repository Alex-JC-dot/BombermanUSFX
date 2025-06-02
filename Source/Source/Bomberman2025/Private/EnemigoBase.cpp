// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoBase.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
// Sets default values
AEnemigoBase::AEnemigoBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass = AAIController::StaticClass();
}

// Called when the game starts or when spawned
void AEnemigoBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigoBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover();
}

// Called to bind functionality to input
void AEnemigoBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void AEnemigoBase::Mover()
{
	AAIController* AIController = Cast<AAIController>(GetController());
	if (AIController)
	{
		APawn* Jugador = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		float Distancia = FVector::Dist(GetActorLocation(), Jugador->GetActorLocation());

		if (Distancia <= GetDistanciaAtaque())
		{
			AIController->StopMovement();

			
			if (AnimacionIdle && bEstaCaminando)
			{
				GetMesh()->PlayAnimation(AnimacionIdle, true);
				bEstaCaminando = false;
			}

			if (bPuedeAtacar)
			{
				Atacar();
				bPuedeAtacar = false;
				GetWorld()->GetTimerManager().SetTimer(TemporizadorReinicioAtaque, this, &AEnemigoBase::ReiniciarAtaque, 1.5f, false);
			}
		}
		else
		{
			AIController->MoveToActor(Jugador, GetDistanciaAtaque());

			// ?? Cambiar a animación de caminar si no estaba caminando
			if (AnimacionCaminar && !bEstaCaminando)
			{
				GetMesh()->PlayAnimation(AnimacionCaminar, true);
				bEstaCaminando = true;
			}
		}
	}
}



void AEnemigoBase::ReiniciarAtaque()
{
	bPuedeAtacar = true;

}

void AEnemigoBase::Atacar()
{
	if (AnimacionAtaque) {
		GetMesh()->PlayAnimation(AnimacionAtaque, false);  // sin loop
		bEstaCaminando = false;
	}
}

void AEnemigoBase::Morir()
{
	if (Vida == 0) {
		if (AnimacionMorir) {
			GetMesh()->PlayAnimation(AnimacionMorir, false);  // sin loop
			bEstaCaminando = false;

			// Espera antes de destruir para que la animación se vea
			GetWorld()->GetTimerManager().SetTimer(
				TemporizadorMuerte, this, &AEnemigoBase::Destruir, 2.0f, false);
		}
	}
}

	void AEnemigoBase::Destruir()
	{
		Destroy();
	}

