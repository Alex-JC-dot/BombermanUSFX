// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"
#include "GameFramework/CharacterMovementComponent.h" // Para movimientos del personaje
#include "Math/UnrealMathUtility.h" // Para FMath::RandRange()
#include "Engine/World.h" // Para GetWorld()
#include "DrawDebugHelpers.h" // Para dibujar líneas de depuración
#include "Engine/StaticMesh.h"            // Para UStaticMesh
#include "Materials/Material.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"			
// Sets default values
AEnemigo::AEnemigo()
{
	// Crear el colisionador
	Colisiones = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Colisiones->SetBoxExtent(FVector(100.0f, 100.0f, 80.0f));
	Colisiones->SetCollisionProfileName(TEXT("BlockAll"));
	Colisiones->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Colisiones->SetGenerateOverlapEvents(true);
	Colisiones->SetHiddenInGame(false);
	Colisiones->SetVisibility(true);

	// Establecer como Root
	RootComponent = Colisiones;

	// Crear la malla del enemigo (Skeletal o Static según tu necesidad)
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MallaEnemigo"));
	Mesh->SetupAttachment(Colisiones);
	Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionProfileName(TEXT("Pawn")); // o "BlockAllDynamic", según el comportamiento

	// Inicializar otras variables
	DistanciaRecorrida = 0.0f;
}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	DrawDebugBox(
		GetWorld(),
		Colisiones->GetComponentLocation(),             // Centro de la caja
		Colisiones->GetScaledBoxExtent(),               // Tamaño
		Colisiones->GetComponentRotation().Quaternion(), // Rotación correcta
		FColor::Red,                                    // Color
		false,                                          // No persistente (solo este frame)
		0.0f,                                           // Tiempo de vida
		0,                                              // Depuración
		2.0f                                            // Grosor
	);
	CambiarDireccion();
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// Detectar obstáculos
	FVector NuevaPosicion = GetActorLocation() + (MovimientoActual * DeltaTime * 400.0F);
	if (DetectarObstaculo(NuevaPosicion))
	{
		CambiarDireccion();
	}
	else
	{
		SetActorLocation(NuevaPosicion);
		DistanciaRecorrida += (MovimientoActual * DeltaTime * 50.0f).Size();

		if (DistanciaRecorrida >= DistanciaMaxima)
		{
			CambiarDireccion();
			DistanciaRecorrida = 0.0f;
		}
	}

	SeguirJugador();
}
void AEnemigo::Destruir()
{
	if (ExplosionesRecibidas >= ExplosionesNecesarias) {
		Destroy();
	}
}

void AEnemigo::AplicarFeedbackVisual()
{
	// Cambiar color del enemigo como señal de daño
	UMeshComponent* Malla = GetMesh(); // Si usas StaticMeshActor en vez de Character, usa Cast<UStaticMeshComponent>(GetComponentByClass(...))
	if (Malla)
	{
		int32 MaterialCount = Malla->GetNumMaterials();
		for (int32 i = 0; i < MaterialCount; i++)
		{
			UMaterialInstanceDynamic* DynMaterial = Malla->CreateAndSetMaterialInstanceDynamic(i);
			if (DynMaterial)
			{
				DynMaterial->SetScalarParameterValue(FName("Dano"), 1.0f); // Este parámetro debe estar en el material
			}
		}
	}
}

void AEnemigo::CambiarDireccion()
{
	int DireccionAleatoria = FMath::RandRange(0, 3);

	switch (DireccionAleatoria)
	{
	case 0: MovimientoActual = FVector(1, 0, 0); break;    // Derecha
	case 1: MovimientoActual = FVector(-1, 0, 0); break;   // Izquierda
	case 2: MovimientoActual = FVector(0, 1, 0); break;    // Adelante
	case 3: MovimientoActual = FVector(0, -1, 0); break;   // Atrás
	}
}
bool AEnemigo::DetectarObstaculo(FVector Destino)
{
	FHitResult HitResult;
	FVector Direccion = (Destino - GetActorLocation()).GetSafeNormal();
	FVector Offset = Direccion * 50.0f;

	FVector Inicio = GetActorLocation() + Offset;
	FVector Fin = Destino + Direccion* 200.0f;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	FVector CajaTamano = FVector(50.0f, 50.0f, 50.0F);
	//Trazar un rayo para detectar obstaculos
	bool bHit = GetWorld()->SweepSingleByChannel(HitResult, Inicio, Fin, FQuat::Identity, ECC_WorldStatic,  FCollisionShape::MakeBox(CajaTamano), Params);

	//dibuja el rayo en el mundo para depuracion
	DrawDebugBox(GetWorld(), Inicio, CajaTamano, FQuat::Identity, FColor::Red, false, 2.0f);
	DrawDebugBox(GetWorld(), Fin, CajaTamano, FQuat::Identity, FColor::Blue, false, 2.0f);
	DrawDebugLine(GetWorld(), Inicio, Fin, FColor::Green, false, 2.0f, 0, 2.0f);
	if (bHit)
	{
		DrawDebugBox(GetWorld(), HitResult.ImpactPoint, FVector(10, 10, 10), FQuat::Identity, FColor::Yellow, false, 2.0f);
	}
	// Si se detecta un obstáculo, cambiar la dirección	
	return bHit;
}

// Called to bind functionality to input
void AEnemigo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
AActor* AEnemigo::GetPlayerActor()
{
	// Obtener referencia al personaje del jugador
	return UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}
IMyPrototype* AEnemigo::Clone()
{
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AEnemigo* NuevoEnemigo = GetWorld()->SpawnActor<AEnemigo>(
		this->GetClass(),          // Clase del objeto actual
		this->GetActorLocation(),  // Posición actual
		this->GetActorRotation(),
		Params
	);

	return Cast<IMyPrototype>(NuevoEnemigo);

}
void AEnemigo::SetPosicion(FVector NuevaPosicion)
{
	SetActorLocation(NuevaPosicion);
}
void AEnemigo::SeguirJugador()
{
	AActor* PlayerActor = GetPlayerActor();
	if (!PlayerActor) return;

	// Calcular distancia al jugador
	float DistanciaJugador = FVector::Dist(GetActorLocation(), PlayerActor->GetActorLocation());

	if (DistanciaJugador <= RadioDeteccion)
	{
		// Mover hacia el jugador
		AAIController* AIController = Cast<AAIController>(GetController());
		if (AIController)
		{
			AIController->MoveToActor(PlayerActor, 5.0f);
		}
	}
}
