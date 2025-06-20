// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalBoss.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "Bomberman2025/Bomberman2025Character.h"
#include "NavigationSystemTypes.h"
#include "EnemigoBase.h"
#include "HUD_Bomberman.h"
#include "Sound/SoundWave.h"
#include "Components/AudioComponent.h"
#include "EnemigoBase_Golbin.h"
#include "Enemigo_GerreroPeon.h"
#include "Enemigo_EsqueletoFinal.h"
#include "Enemigo_EsqueletoPeon.h"
#include "EnemigoBase_GolemPeon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AIController.h"
#include "Navigation/PathFollowingComponent.h"

// Sets default values
AFinalBoss::AFinalBoss()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MallaEnemigo(TEXT("/Script/Engine.SkeletalMesh'/Game/Hechos/Cementerio/Enemigos/FinalBoss/Unarmed_Walk_Forward.Unarmed_Walk_Forward'"));
    if (MallaEnemigo.Succeeded())
    {

        GetMesh()->SetSkeletalMesh(MallaEnemigo.Object);
        GetMesh()->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
        GetMesh()->SetRelativeRotation(FRotator(0.0f,90.0f,0.0f));
        GetMesh()->SetRelativeLocation(FVector(0.f, 0.0f, 0.0f));

    }
    static ConstructorHelpers::FObjectFinder<UAnimSequence> WalkAnim(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/FinalBoss/Unarmed_Walk_Forward_Anim.Unarmed_Walk_Forward_Anim'"));
    if (WalkAnim.Succeeded())
    {
        AnimacionCaminar = WalkAnim.Object;
    }


    static ConstructorHelpers::FObjectFinder<UAnimSequence> AtaqueObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/FinalBoss/Standing_Melee_Combo_Attack_Ver__1.Standing_Melee_Combo_Attack_Ver__1'"));
    if (AtaqueObj.Succeeded())
    {
        AnimacionAtaque = AtaqueObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> MoriroObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/FinalBoss/Dying.Dying'"));
    if (MoriroObj.Succeeded())
    {
        AnimacionMorir = MoriroObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> GritoObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/FinalBoss/Standing_Taunt_Battlecry.Standing_Taunt_Battlecry'"));
    if (GritoObj.Succeeded())
    {
        AnimacionGrito = GritoObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UAnimSequence> AtaqueLargaDistanciaObj(TEXT("/Script/Engine.AnimSequence'/Game/Hechos/Cementerio/Enemigos/FinalBoss/Standing_Melee_Run_Jump_Attack.Standing_Melee_Run_Jump_Attack'"));
    if (AtaqueLargaDistanciaObj.Succeeded())
    {
        AnimacionAtaqueDistancia = AtaqueLargaDistanciaObj.Object;
    }
    //Niagara

    static ConstructorHelpers::FObjectFinder<UNiagaraSystem> NiagaraAsset(TEXT("Niagara.NiagaraSystem'/Game/sA_Megapack_v1/sA_StylizedAttacksPack/FX/NiagaraSystems/NS_AOE_Explosion_1.NS_AOE_Explosion_1'"));
    if (NiagaraAsset.Succeeded())
    {
        NiagaraAtaqueFinalizado = NiagaraAsset.Object;
    }
    static ConstructorHelpers::FObjectFinder<UNiagaraSystem> NiagaraAurAAsset(TEXT("NiagaraSystem'/Game/sA_Megapack_v1/sA_StylizedAttacksPack/FX/NiagaraSystems/NS_Aura.NS_Aura'"));
    if (NiagaraAurAAsset.Succeeded())
    {
        EfectoAuraNiagara = NiagaraAurAAsset.Object;
    }
    //sonido
    static ConstructorHelpers::FObjectFinder<USoundBase> SonidoGritoAsset(TEXT("/ Script / Engine.SoundWave'/Game/Hechos/Cementerio/Enemigos/FinalBoss/Sonidos/monster-screams.monster-screams'")); // Ruta correcta para el sonido
    if (SonidoGritoAsset.Succeeded())
    {
        SonidoGrito = SonidoGritoAsset.Object;
    } 
    //sonido
    static ConstructorHelpers::FObjectFinder<USoundBase> SonidoMuerteAsset(TEXT("/Script/Engine.SoundWave'/Game/Hechos/Cementerio/Enemigos/FinalBoss/Sonidos/monster-scream_Death.monster-scream_Death'")); 
    if (SonidoMuerteAsset.Succeeded())
    {
        SonidoMuerte = SonidoMuerteAsset.Object;
    }

    static ConstructorHelpers::FObjectFinder<USoundBase> SonidoEspadaAsset(TEXT("/Script/Engine.SoundWave'/Game/Hechos/Cementerio/Enemigos/FinalBoss/Sonidos/533361__fivebrosstopmosyt__vibrosword-clash-1.533361__fivebrosstopmosyt__vibrosword-clash-1'"));
    if (SonidoEspadaAsset.Succeeded())
    {
        SonidoEspada = SonidoEspadaAsset.Object;
    }
    static ConstructorHelpers::FObjectFinder<USoundBase> AudioCombateAsset(TEXT("/Script/Engine.SoundWave'/Game/Hechos/Musica/SpotiMate_io_-_Let_the_Battles_Begin___From__Final_Fantasy_VII___-_Cover_Version_-_GaMetal.SpotiMate_io_-_Let_the_Battles_Begin___From__Final_Fantasy_VII___-_Cover_Version_-_GaMetal'"));
    if (AudioCombateAsset.Succeeded())
    {
        SonidoBossBattle= AudioCombateAsset.Object;
    }



    ComponenteAura = CreateDefaultSubobject<UNiagaraComponent>(TEXT("AuraNiagara"));
    ComponenteAura->SetupAttachment(GetMesh());
    ComponenteAura->bAutoActivate = true;
    ComponenteAura->SetRelativeScale3D(FVector(4.0f));

    VidaMaxima = 2500.0f;
    VidaActual = VidaMaxima;
    FaseActual = EFaseHorda::Fase1;
    VelocidadBase = 250.0f;

    TiempoEntrePatrullas = 0.5f;
    RadioPatrullaje = 1000.0f;
    bPersiguiendoJugador = false;

    AIControllerClass = AAIController::StaticClass();
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    
    ClaseEnemigoComun = AEnemigo_EsqueletoPeon::StaticClass();
    ClaseEnemigoFuerte = AEnemigo_EsqueletoFinal::StaticClass();
}


// Called when the game starts or when spawned
void AFinalBoss::BeginPlay()
{
	Super::BeginPlay();

    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PC)
    {
        AHUD_Bomberman* HUD = Cast<AHUD_Bomberman>(PC->GetHUD());
        if (HUD)
        {
            HUD->MostrarBarraVidaJefe();
        }
    }
 
    GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.0f, -90.0f));

    TiempoSiguientePatrulla = GetWorld()->GetTimeSeconds() + TiempoEntrePatrullas;

    // Configura la velocidad inicial
    GetCharacterMovement()->MaxWalkSpeed = VelocidadBase;
    ReproducirAnimacionInicial();

    ComenzarBatalla();
}

// Called every frame
void AFinalBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


    DetectarYPerseguirJugador();  

    ActualizarFase(); 


}

void AFinalBoss::ActualizarFase()
{
    EFaseHorda FaseAnterior = FaseActual;

    // Determinar la fase según la vida actual
    float VidaRatio = VidaActual / VidaMaxima;

    if (VidaRatio <= 0.25f)
        FaseActual = EFaseHorda::Fase4;
    else if (VidaRatio <= 0.50f)
        FaseActual = EFaseHorda::Fase3;
    else if (VidaRatio <= 0.75f)
        FaseActual = EFaseHorda::Fase2;
    else
        FaseActual = EFaseHorda::Fase1;

    // Usar switch para ajustar velocidad y otras acciones según fase
    switch (FaseActual)
    {
    case EFaseHorda::Fase1:
        VelocidadBase = 250.0f;
        break;

    case EFaseHorda::Fase2:
        VelocidadBase = 270.0f;
        break;

    case EFaseHorda::Fase3:
        VelocidadBase = 350.0f;
        break;

    case EFaseHorda::Fase4:
        VelocidadBase = 400.0f;
        break;
    }

    // Si cambió de fase, invoca enemigos
    if (FaseActual != FaseAnterior)
    {
        EjecutarGritoEInvocacion();
       
    }

    // Actualiza la velocidad de movimiento
    GetCharacterMovement()->MaxWalkSpeed = VelocidadBase;
}


void AFinalBoss::InvocarEnemigos()
{
    if (!ClaseEnemigoComun || !ClaseEnemigoFuerte) return;

    int CantidadEnemigos = FaseActual == EFaseHorda::Fase1 ? 1 :
        FaseActual == EFaseHorda::Fase2 ? 2 :
        FaseActual == EFaseHorda::Fase3 ? 3 : 4;

    for (int i = 0; i < CantidadEnemigos; i++)
    {
        FVector Offset = FVector(FMath::RandRange(-600, 600), FMath::RandRange(-600, 600), 50);
        FVector SpawnLocation = GetActorLocation() + Offset;

   
        GetWorld()->SpawnActor<AEnemigo_EsqueletoFinal>(AEnemigo_EsqueletoFinal::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
        GetWorld()->SpawnActor<AEnemigo_EsqueletoPeon>(AEnemigo_EsqueletoPeon::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
    }
}
void AFinalBoss::EjecutarGritoEInvocacion()
{
    if (bEstaMuerto || !AnimacionGrito) return;


    GetMesh()->Stop();


    GetMesh()->PlayAnimation(AnimacionGrito, false);

    float DuracionGrito = AnimacionGrito->GetPlayLength();
    if (ComponenteAura && EfectoAuraNiagara)
    {
        ComponenteAura->SetAsset(EfectoAuraNiagara);
        ComponenteAura->Activate(true);
    }
    if (SonidoGrito)
    {
        UGameplayStatics::PlaySoundAtLocation(this, SonidoGrito, GetActorLocation(), 1.0f);
    }

    GetWorldTimerManager().SetTimer(TemporizadorGrito, this, &AFinalBoss::FinalizarGritoEInvocar, DuracionGrito, false);
}


void AFinalBoss::FinalizarGritoEInvocar()
{
    InvocarEnemigos();

 


    if (!bEstaMuerto && AnimacionCaminar)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
        bEstaCaminando = true;
    }
}


void AFinalBoss::DetectarYPerseguirJugador()
{
    if (bEstaMuerto || bEstaAtacando) return; 

    AActor* Jugador = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (!Jugador) return;

    float Distancia = FVector::Dist(GetActorLocation(), Jugador->GetActorLocation());

    AAIController* AIController = Cast<AAIController>(GetController());

    if (Distancia <= RangoAtaque)
    {
        AtacarJugador();
        if (AIController) AIController->StopMovement();
    }
    else
    {
        bPersiguiendoJugador = true;
        MoveToLocation(Jugador->GetActorLocation());

        if (AnimacionCaminar && !bEstaCaminando)
        {
            GetMesh()->PlayAnimation(AnimacionCaminar, true);
            bEstaCaminando = true;
        }
    }
}

void AFinalBoss::TerminarAtaque()
{
    bEstaAtacando = false;

    
    if (!bEstaMuerto && AnimacionCaminar)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
        bEstaCaminando = true;
    }


 
}

void AFinalBoss::MoveToLocation(const FVector& Destino)
{
    AAIController* AIController = Cast<AAIController>(GetController());
    if (!AIController)
    {
        GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("FinalBoss no tiene AIController asignado."));
        return;
    }


        FAIMoveRequest MoveRequest;
        MoveRequest.SetGoalLocation(Destino);
        MoveRequest.SetAcceptanceRadius(5.0f);

        FNavPathSharedPtr NavPath;
        AIController->MoveTo(MoveRequest, &NavPath);
    
}

void AFinalBoss::AtacarJugador()
{
    if (bEstaMuerto || bEstaAtacando || !AnimacionAtaque) return;

    bEstaAtacando = true;
    bEstaCaminando = false;

    GetMesh()->Stop();
    GetMesh()->PlayAnimation(AnimacionAtaque, false);

    float Duracion = AnimacionAtaque->GetPlayLength();

    // Temporizador para terminar ataque
    GetWorldTimerManager().SetTimer(TemporizadorAtaque, this, &AFinalBoss::TerminarAtaque, Duracion, false);

    // Temporizador para aplicar daño a mitad de la animación (por ejemplo, al 50%)
    float MomentoImpacto = Duracion * 0.5f;
    GetWorldTimerManager().SetTimer(TemporizadorDano, this, &AFinalBoss::AplicarDanoAlJugador, MomentoImpacto, false);
}

void AFinalBoss::AplicarDanoAlJugador()
{
    APawn* JugadorPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    ABomberman2025Character* JugadorRef = Cast<ABomberman2025Character>(JugadorPawn);

    if (!JugadorRef) return;

    float Distancia = FVector::Dist(GetActorLocation(), JugadorRef->GetActorLocation());
    float RangoImpactoEstampida = 300.0f;

    if (Distancia <= RangoImpactoEstampida)
    {
        JugadorRef->RecibirDano(20.0f);
    }
    if (NiagaraAtaqueFinalizado)
    {
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),NiagaraAtaqueFinalizado,GetActorLocation()+FVector(0.0f,500.0f,100.0f), GetActorRotation());
    }
    if (SonidoEspada)
    {
        UGameplayStatics::PlaySoundAtLocation(this, SonidoEspada, GetActorLocation(), 0.4f);
    }
}



void AFinalBoss::RecibirDano(float Cantidad)
{

    if (bEstaMuerto || Cantidad <= 0.f) return;

    VidaActual -= Cantidad;
    
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0); // Declaración UNA vez
    if (PC)
    {
        AHUD_Bomberman* HUD = Cast<AHUD_Bomberman>(PC->GetHUD());
        if (HUD && HUD->WidgetBarraVidaJefe)
        {
            HUD->WidgetBarraVidaJefe->ActualizarBarraVida(VidaActual, VidaMaxima);
        }
    }

    if (VidaActual <= 0.f)
    {
        VidaActual = 0.f;
        bEstaMuerto = true;

        AAIController* AIController = Cast<AAIController>(GetController());
        if (AIController)
        {
            AIController->StopMovement();
        }

        GetCharacterMovement()->DisableMovement();
        SetLifeSpan(5.0f);

        if (PC) // ? Reutilizando la variable ya declarada
        {
            AHUD_Bomberman* HUD = Cast<AHUD_Bomberman>(PC->GetHUD());
            if (HUD)
            {
                HUD->OcultarBarraVidaJefe();
            }
        }
        if (SonidoMuerte)
        {
            UGameplayStatics::PlaySoundAtLocation(this, SonidoMuerte, GetActorLocation(), 1.0f);
        }
        if (AudioBossBattle && AudioBossBattle->IsPlaying())
        {
            AudioBossBattle->FadeOut(3.0f, 0.0f); 

            
        }

        if (AnimacionMorir && GetMesh())
        {
            GetMesh()->Stop();
            GetMesh()->PlayAnimation(AnimacionMorir, false);
        }
    }
}


void AFinalBoss::ReproducirAnimacionInicial()
{

    if (AnimacionCaminar)
    {
        GetMesh()->PlayAnimation(AnimacionCaminar, true);
        bEstaCaminando = true;
    }
}
void AFinalBoss::ComenzarBatalla()
{
    if (SonidoBossBattle)
    {
        AudioBossBattle = UGameplayStatics::SpawnSound2D(this, SonidoBossBattle, 0.4f, 1.0f, 0.0f, nullptr, true);
    }
}