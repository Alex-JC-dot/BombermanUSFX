// Copyright Epic Games, Inc. All Rights Reserved.

#include "Bomberman2025Character.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Bomba.h"
#include "HUD_Bomberman.h"
#include "GameInstance_Datos.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ABomberman2025Character

ABomberman2025Character::ABomberman2025Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configura la cápsula de colisión

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 550.0f; // Default distance
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	
	CameraBoom->SetRelativeLocation(FVector(0.f, 0.f, 150.f)); // Sube la cámara
	CameraBoom->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach camera to boom
	FollowCamera->bUsePawnControlRotation = false; // Camera doesn't rotate relative to arm

	static ConstructorHelpers::FClassFinder<UUserWidget> HUDWidgetClass(TEXT("/Game/GameModeCasero/UI/W_HUDBomberman"));
	if (HUDWidgetClass.Succeeded())
	{
		WidgetClaseHUD = HUDWidgetClass.Class;
	}
	static ConstructorHelpers::FObjectFinder<UAnimSequence> MoriroObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Bomberman/Animations/Sword_And_Shield_Death.Sword_And_Shield_Death'"));
	if (MoriroObj.Succeeded())
	{
		AnimacionMorir = MoriroObj.Object;
	}
	static ConstructorHelpers::FObjectFinder<USoundBase> SonidoColocarBombaAsset(TEXT("/Script/Engine.SoundWave'/Game/GameModeCasero/Sonidos/352118__inspectorj__dropping-wood-j.352118__inspectorj__dropping-wood-j'")); // Ruta correcta para el sonido
	if (SonidoColocarBombaAsset.Succeeded())
	{
		SonidoColocarBomba = SonidoColocarBombaAsset.Object;
	}
}


//////////////////////////////////////////////////////////////////////////
// Input

void ABomberman2025Character::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* Player= GetWorld()->GetFirstPlayerController();

	if (WidgetClaseHUD)
	{
		WidgetHUD = CreateWidget<UW_HUDBomberman>(Player, WidgetClaseHUD);
		if (WidgetHUD)
		{
			WidgetHUD->AddToViewport();
			WidgetHUD->ActualizarBombas(BombasDisponibles);
			WidgetHUD->ActualizarVida(ObtenerVidaPorcentaje());
		}
	}
	GetWorldTimerManager().SetTimer(TimerHandle_RegenerarBomba, this, &ABomberman2025Character::RegenarBomba, 5.0f, true);
	UGameInstance_Datos* Datos = Cast<UGameInstance_Datos>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (Datos)
	{
		VidaActual = Datos->ObtenerVidaActual();
		VidaMaxima = Datos->ObtenerVidaMax();
	}
}

void ABomberman2025Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABomberman2025Character::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ABomberman2025Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABomberman2025Character::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABomberman2025Character::Look);

		// Pu a Bomb
		EnhancedInputComponent->BindAction(PutBombAction, ETriggerEvent::Started, this, &ABomberman2025Character::PutBom);

	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ABomberman2025Character::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ABomberman2025Character::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ABomberman2025Character::PutBom(const FInputActionValue& Value)
{
	if (bEstaMuerto) return;
	if (BombasDisponibles <= 0)
	{ 
	
		return;
	}

	if (BombasDisponibles > 0) {
		ABomba* Bomba = GetWorld()->SpawnActor<ABomba>(ABomba::StaticClass(), GetActorLocation() + FVector(0.0f, 0.0f, -67.0f), FRotator::ZeroRotator);
		if (SonidoColocarBomba)
		{
			UGameplayStatics::PlaySoundAtLocation(this, SonidoColocarBomba, GetActorLocation(), 0.5f);
		}
		if (Bomba)
		{
			Bomba->CantidadExplosion = AlcanceExplosion;
			Bomba->SetOwner(this);
			BombasDisponibles--;
			WidgetHUD->ActualizarBombas(BombasDisponibles);
		}
	}
}


void ABomberman2025Character::RecibirDano(int dano)
{

	if (bEstaMuerto) return;

	VidaActual -= dano;
	VidaActual = FMath::Clamp(VidaActual, 0.0f, VidaMaxima);

	if (WidgetHUD)
	{
		WidgetHUD->ActualizarVida(ObtenerVidaPorcentaje());
	}

	ContadorParpadeo = 0;
	GetWorldTimerManager().SetTimer(TimerHandle_Parpadeo, this, &ABomberman2025Character::Parpadear, 0.1f, true);
	
	if (VidaActual <= 0) 
	{
		bEstaMuerto = true;
		if (AnimacionMorir)
		{
			AController* Controlador = GetController();
			if (Controlador)
			{
				Controlador->SetIgnoreMoveInput(true);
				Controlador->SetIgnoreLookInput(true);
			}

			GetMesh()->PlayAnimation(AnimacionMorir, false);

			float Duracion = AnimacionMorir->GetPlayLength();
			GetWorldTimerManager().SetTimer(TimerHandle_Morir, this, &ABomberman2025Character::Morir, Duracion, false);
		}
		else
		{
			Destroy();
		}
	}

}
void ABomberman2025Character::Morir()
{
	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Green,TEXT("Jugador murio"));

	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		AHUD_Bomberman* HUD = Cast<AHUD_Bomberman>(PC->GetHUD());
		if (HUD)
		{
			HUD->MostrarPantallaGameOver();
		}

		PC->SetPause(true); // Pausar el juego

		// Evita entrada y oculta al personaje
		DisableInput(PC);
		GetMesh()->SetVisibility(false);
		SetActorEnableCollision(false);
	}

}
void ABomberman2025Character::Parpadear()
{
	bool Visible = GetMesh()->IsVisible();
	GetMesh()->SetVisibility(!Visible);

	ContadorParpadeo++;

	if (ContadorParpadeo >= 6) 
	{
		GetMesh()->SetVisibility(true); 
		GetWorldTimerManager().ClearTimer(TimerHandle_Parpadeo);
	}
}

void ABomberman2025Character::RegenarBomba()
{
	if (BombasDisponibles < BombasMaximas)
	{
		BombasDisponibles++;
		WidgetHUD->ActualizarBombas(BombasDisponibles);
	}
}
