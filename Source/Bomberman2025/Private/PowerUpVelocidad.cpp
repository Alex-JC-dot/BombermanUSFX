// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpVelocidad.h"
#include "GameFramework/CharacterMovementComponent.h"



// Sets default values
APowerUpVelocidad::APowerUpVelocidad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	
		static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaPoweUpVelocity(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/PowerUp/Velocidad/Velocidad.Velocidad'"));
		if (MallaPoweUpVelocity.Succeeded())
		{
			Mesh->SetSkeletalMesh(MallaPoweUpVelocity.Object);
			Mesh->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));

			Mesh->SetWorldScale3D(FVector(0.15, 0.15, 0.15));
		}
		Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
		Collision->SetupAttachment(RootComponent);
		Collision->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
		Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic")); // Importante para que detecte overlaps
		// Conectamos al evento de colisi?n
		Collision->OnComponentBeginOverlap.AddDynamic(this, &APowerUpVelocidad::OnOverlapBegin);
}

// Called when the game starts or when spawned
void APowerUpVelocidad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerUpVelocidad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, 60 * DeltaTime, 0));
}



void APowerUpVelocidad::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		ABomberman2025Character* Player = Cast<ABomberman2025Character>(OtherActor);
		if (Player)
		{
			VelocidadOriginal = Player->GetCharacterMovement()->MaxWalkSpeed;
			Player->GetCharacterMovement()->MaxWalkSpeed += 500.0f;

			JugadorAfectado = Player; 

			GetWorldTimerManager().SetTimer(TimerHandle_Velocidad, this, &APowerUpVelocidad::RestaurarVelocidad, DuracionVelocidad, false);

			SetActorHiddenInGame(true);
			SetActorEnableCollision(false);
		}
	}

}

void APowerUpVelocidad::RestaurarVelocidad()
{

	if (IsValid(JugadorAfectado))
	{
		JugadorAfectado->GetCharacterMovement()->MaxWalkSpeed = VelocidadOriginal;
		
	}

	Destroy();
	
}

