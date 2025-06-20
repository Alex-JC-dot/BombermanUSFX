// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomba.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "Bomberman2025/Bomberman2025Character.h"
#include "Explosion.h"
#include "ProyectilDestructor.h" 
#include "Bloque.h"
// Sets default values
ABomba::ABomba()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	RootComponent = Mesh;
	auto Asset = ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Bomba/Bomba.Bomba'"));
	if (Asset.Object != nullptr) {

		Mesh->SetSkeletalMesh(Asset.Object);
	
	}
	//EscalaTope = FVector(FMath::RandRange(4.0f*2,6.0f*2), FMath::RandRange(4.0f * 2, 6.0f * 2), FMath::RandRange(4.0f * 2, 6.0f * 2));
	EscalaTope = FVector(3.5f, 3.5f, 3.5f);


	//sonido
	static ConstructorHelpers::FObjectFinder<USoundBase> SonidoAsset(TEXT("/Script/Engine.SoundWave'/Game/StarterContent/Audio/Explosion01.Explosion01'")); // Ruta correcta para el sonido
	if (SonidoAsset.Succeeded())
	{
		Sonido = SonidoAsset.Object; // Asignación del sonido de colisión
	}
}

// Called when the game starts or when spawned
void ABomba::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CrecimientoVelocidad(DeltaTime);
	EscalaActual = GetActorScale3D();
	if (EscalaActual.X >= EscalaTope.X &&EscalaActual.Y >= EscalaTope.Y &&EscalaActual.Z >= EscalaTope.Z) {
		Activado = false;
		SpawnExplosion();
		Destroy();		
	}
	Crecimiento(DeltaTime);
}

void ABomba::CrecimientoVelocidad(float deltatime)
{	
	if (VelocidadActiva) {
		Velocidad += aceleracion*deltatime;

		if (Velocidad >= velocidadtope) {
			VelocidadActiva = false;
		}
	}
}

//bool ABomba::HayBombasCerca(const FVector& Posicion, float RadioDeteccion) const
//{
//	return FVector::Dist(GetActorLocation(), Posicion) <= RadioDeteccion;
//}



void ABomba::Crecimiento(float time)
{	
	if (!Activado) {
		return;
	}
	EscalaActual = GetActorScale3D();
	if (Activado) {
		EscalaActual = EscalaActual + FVector(time * Velocidad, time * Velocidad, time * Velocidad);
	}
	
	SetActorScale3D(EscalaActual);

}
void ABomba::SpawnExplosion()
{
	
	if (GetWorld()) 
	{
		
			AExplosion*Explosion=GetWorld()->SpawnActor<AExplosion>(AExplosion::StaticClass(), GetActorLocation(), FRotator::ZeroRotator);
			if (Explosion) {
				Explosion->SetLifeSpan(1.5f);
				if (Sonido)
				{
					UGameplayStatics::PlaySoundAtLocation(this, Sonido, GetActorLocation(), 0.5f);
				}
			}
			if (Explosion) 
			{

			}

			for (FVector Dir : Direcciones)
			{
				for (int i = 1; i <= CantidadExplosion; ++i)
				{
					FVector Start = GetActorLocation();
					FVector End = Start + Dir * i;

					FHitResult Hit;
					FCollisionQueryParams Params;
					Params.AddIgnoredActor(this);

					bool bHit = GetWorld()->SweepSingleByChannel(
						Hit,
						Start,
						End,
						FQuat::Identity,
						ECC_Visibility,
						FCollisionShape::MakeSphere(25.0f),
						Params
					);

					if (bHit)
					{
						ABloque* BloqueDetectado = Cast<ABloque>(Hit.GetActor());
						if (BloqueDetectado)
						{
							if (BloqueDetectado->Destructible)
							{
								BloqueDetectado->Destruir();
								SpawnExplosionEn(Hit.Location);
								// NO hacemos break, sigue la explosión
							}
							else
							{
							
								break;
							}
						}
						else
						{
					
							break;
						}
					}
					else
					{
						
						SpawnExplosionEn(End);
					}
				}
			}			
			Destroy();

	}
}

void ABomba::SpawnExplosionEn(FVector Pos)
{
	AExplosion* NuevaExplosion = GetWorld()->SpawnActor<AExplosion>(AExplosion::StaticClass(), Pos, FRotator::ZeroRotator);
	if (NuevaExplosion)
	{
		NuevaExplosion->SetLifeSpan(1.5f);
	
	}
}


