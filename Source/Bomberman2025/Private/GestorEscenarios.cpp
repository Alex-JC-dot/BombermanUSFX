// Fill out your copyright notice in the Description page of Project Settings.


#include "GestorEscenarios.h"
#include "BuilderAntiguo.h"
#include "Kismet/GameplayStatics.h"
#include "LaberintoTerminado.h"



UGestorEscenarios::UGestorEscenarios()
{
    LaberintoFinal = nullptr;
    Horda = nullptr;
    GestorEnemigos = nullptr;
    DirectorLaberinto = nullptr;
    DirectorEnemigos = nullptr;
    BuilderAbstracto = nullptr;
    BuilderAntiguo = nullptr;
    BuilderHielo = nullptr;
    BuilderCementerio = nullptr;
    BuilderUrbano = nullptr;
    BuilderLava = nullptr;
    BuilderMedieval = nullptr;
    BuilderHordaEsqueleto = nullptr;
    BuilderHordaGuerrero = nullptr;

    static ConstructorHelpers::FObjectFinder<USoundBase> MusicaAntiguaAsset(TEXT("/Script/Engine.SoundWave'/Game/GameModeCasero/Sonidos/SpotiMate_io_-_Bomberman_Hero__Milky_-_Arcade_Player.SpotiMate_io_-_Bomberman_Hero__Milky_-_Arcade_Player'"));
    if (MusicaAntiguaAsset.Succeeded())
    {
        MusicaAntigua = MusicaAntiguaAsset.Object;
    }
    static ConstructorHelpers::FObjectFinder<USoundBase> MusicaHieloAsset(TEXT("/Script/Engine.SoundWave'/Game/GameModeCasero/Sonidos/SpotiMate_io_-_Bomberman_64__Introduction_-_Arcade_Player.SpotiMate_io_-_Bomberman_64__Introduction_-_Arcade_Player'"));
    if (MusicaHieloAsset.Succeeded())
    {
        MusicaHielo = MusicaHieloAsset.Object;
    }
    static ConstructorHelpers::FObjectFinder<USoundBase> MusicaUrbanaAsset(TEXT("/Script/Engine.SoundWave'/Game/GameModeCasero/Sonidos/SpotiMate_io_-_Bomberman_64_-_The_Second_Attack___Sthertoth_Battle_-_Arcade_Player.SpotiMate_io_-_Bomberman_64_-_The_Second_Attack___Sthertoth_Battle_-_Arcade_Player'"));
    if (MusicaUrbanaAsset.Succeeded())
    {
        MusicaUrbana = MusicaUrbanaAsset.Object;
    }

}
FName UGestorEscenarios::ObtenerNombreNivelDesdeEscenario(ETipoEscenario TipoEscenario)
{
    switch (TipoEscenario)
    {
    case ETipoEscenario::Antiguo:      return FName(TEXT("NivelAntiguo"));
    case ETipoEscenario::Cementerio:   return FName(TEXT("NivelCementerio"));
    case ETipoEscenario::Urbano:       return FName(TEXT("NivelCiudad"));
    case ETipoEscenario::Lava:         return FName(TEXT("NivelMagma"));
    case ETipoEscenario::Hielo:        return FName(TEXT("NivelHielo"));
    case ETipoEscenario::Desierto:     return FName(TEXT("NivelDesierto"));
    case ETipoEscenario::Medieval:     return FName(TEXT("NivelMedieval"));
    default:                          return NAME_None;
    }

}
void UGestorEscenarios::ConstruirEscenario(UWorld* Mundo, ETipoEscenario Escenario)
{
    if (!IsValid(Mundo))
    {

        GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, TEXT("Mundo Invalido"));

        return;
    }

 

    // Guardar referencias
    MundoGuardado = Mundo;
    EscenarioGuardado = Escenario;

 /*   DestruirEscenarioActual();*/
    // Configurar timer seguro

    Mundo->GetTimerManager().ClearTimer(TimerHandle_ConstruirEscenario);
    Mundo->GetTimerManager().SetTimer(TimerHandle_ConstruirEscenario, this,
        &UGestorEscenarios::ConstruirEscenarioContinuar, 0.1f, false);
}
void UGestorEscenarios::ConstruirEscenarioContinuar()
{
  

    // Crear directores
    DirectorEnemigos = MundoGuardado->SpawnActor<ADirector_Enemigos>();
    DirectorLaberinto = MundoGuardado->SpawnActor<ADirector>();

    if (!IsValid(DirectorEnemigos) || !IsValid(DirectorLaberinto))
    {
      
        return;
    }

    switch (EscenarioGuardado)
    {
    case ETipoEscenario::Antiguo:
    {
        BuilderAntiguo = MundoGuardado->SpawnActor<ABuilderAntiguo>();
        if (!IsValid(BuilderAntiguo))
        {
            
            return;
        }

        DirectorLaberinto->LlamarConstructor(BuilderAntiguo);

        BuilderHordaGuerrero = MundoGuardado->SpawnActor<ABuilderHordaGuerrero>();
        if (!IsValid(BuilderHordaGuerrero))
        {
        
            return;
        }

        DirectorEnemigos->LlamarConstructor(BuilderHordaGuerrero);

        auto BuilderInterface = GetBuilderInterfaceFromActor(BuilderAntiguo);
        if (!BuilderInterface)
        {
       
            return;
        }

        if (!GestorEnemigos)
        {
            GestorEnemigos = MundoGuardado->SpawnActor<AGestorEnemigos>();
            if (!IsValid(GestorEnemigos))
            {
               
                return;
            }
          
        }

        ReproducirMusicaDeNivel(MusicaAntigua);
        GestorEnemigos->EstablecerBuilder(BuilderInterface);
        break;
    }
    case ETipoEscenario::Cementerio:
    {
        BuilderCementerio = MundoGuardado->SpawnActor<ABuilderCementerio>();
        if (!IsValid(BuilderCementerio))
        {
          
            return;
        }

        DirectorLaberinto->LlamarConstructor(BuilderCementerio);

        BuilderHordaEsqueleto = MundoGuardado->SpawnActor<ABuiilderHordaEsqueleto>();
        if (!IsValid(BuilderHordaEsqueleto))
        {
            
            return;
        }

        DirectorEnemigos->LlamarConstructor(BuilderHordaEsqueleto);

        if (!GestorEnemigos)
        {
            GestorEnemigos = MundoGuardado->SpawnActor<AGestorEnemigos>();
            if (!IsValid(GestorEnemigos))
            {
                
                return;
            }
        }

        GestorEnemigos->EstablecerBuilder(BuilderCementerio);
        break;
    }
    case ETipoEscenario::Urbano:
    {
        auto Builder = MundoGuardado->SpawnActor<ABuilderConcreto>();
        if (!IsValid(Builder))
        {
           
            return;
        }

        DirectorLaberinto->LlamarConstructor(Builder);
        BuilderHordaUrbana = MundoGuardado->SpawnActor < ABuilderHordaUrbana > ();
        if (!IsValid(BuilderHordaUrbana))
        {
            
            return;
        }
        ReproducirMusicaDeNivel(MusicaUrbana);
        DirectorEnemigos->LlamarConstructor(BuilderHordaUrbana);
        break;
    }
    case ETipoEscenario::Desierto:
    {
        auto Builder = MundoGuardado->SpawnActor<ABuilderDesierto>();
        if (!IsValid(Builder))
        {
         
            return;
        }
        DirectorLaberinto->LlamarConstructor(Builder);
        BuilderHordaEsqueleto = MundoGuardado->SpawnActor<ABuiilderHordaEsqueleto>();
        if (!IsValid(BuilderHordaEsqueleto))
        {
       
            return;
        }

        DirectorEnemigos->LlamarConstructor(BuilderHordaEsqueleto);

        if (!GestorEnemigos)
        {
            GestorEnemigos = MundoGuardado->SpawnActor<AGestorEnemigos>();
            if (!IsValid(GestorEnemigos))
            {
            
                return;
            }
        }
        GestorEnemigos->EstablecerBuilder(BuilderCementerio);
        break;
    }
    case ETipoEscenario::Lava:
    {
        auto Builder = MundoGuardado->SpawnActor<ABuilderLava>();
        if (!IsValid(Builder))
        {
         
            return;
        }
        DirectorLaberinto->LlamarConstructor(Builder);
        BuilderHordaHielo = MundoGuardado->SpawnActor<ABuilderHordaHielo>();
        if (!IsValid(BuilderHordaHielo))
        {
          
            return;
        }

        DirectorEnemigos->LlamarConstructor(BuilderHordaHielo);

        if (!GestorEnemigos)
        {
            GestorEnemigos = MundoGuardado->SpawnActor<AGestorEnemigos>();
            if (!IsValid(GestorEnemigos))
            {
            
                return;
            }
        }
        GestorEnemigos->EstablecerBuilder(BuilderHielo);
        break;
    }
    case ETipoEscenario::Hielo:
    {
        BuilderHielo = MundoGuardado->SpawnActor<ABuilderHielo>();
        if (!IsValid(BuilderHielo))
        {
          
            return;
        }

        DirectorLaberinto->LlamarConstructor(BuilderHielo);

        BuilderHordaHielo = MundoGuardado->SpawnActor<ABuilderHordaHielo>();
        if (!IsValid(BuilderHordaHielo))
        {
           
            return;
        }

        DirectorEnemigos->LlamarConstructor(BuilderHordaHielo);

        if (!GestorEnemigos)
        {
            GestorEnemigos = MundoGuardado->SpawnActor<AGestorEnemigos>();
            if (!IsValid(GestorEnemigos))
            {
              
                return;
            }
        }
        ReproducirMusicaDeNivel(MusicaHielo);
        GestorEnemigos->EstablecerBuilder(BuilderHielo);
        break;
    }
    case ETipoEscenario::Medieval:
    {
        auto Builder = MundoGuardado->SpawnActor<ABuilderMedieval>();
        if (!IsValid(Builder))
        {
           
            return;
        }
        DirectorLaberinto->LlamarConstructor(Builder);
        BuilderHordaGuerrero = MundoGuardado->SpawnActor<ABuilderHordaGuerrero>();
        if (!IsValid(BuilderHordaHielo))
        {
         
            return;
        }

        DirectorEnemigos->LlamarConstructor(BuilderHordaGuerrero);

        if (!GestorEnemigos)
        {
            GestorEnemigos = MundoGuardado->SpawnActor<AGestorEnemigos>();
            if (!IsValid(GestorEnemigos))
            {
               
                return;
            }
        }
        GestorEnemigos->EstablecerBuilder(BuilderMedieval);
        break;
    }
    default:
    {
      
        return;
    }
    }

    if (!IsValid(DirectorLaberinto) || !IsValid(DirectorEnemigos))
    {
       
        return;
    }

    DirectorLaberinto->ConstruirLaberinto();
    DirectorEnemigos->ConstruirHorda();
    Horda = DirectorEnemigos->GetHorda();
    LaberintoFinal = DirectorLaberinto->GetLaberinto();

   /* GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, TEXT("Nuevo escenario construido"));*/

}
void UGestorEscenarios::ReproducirMusicaDeNivel(USoundBase* Musica)
{
    if (!Musica || !MundoGuardado)
    {
        
        return;
    }

    // Fade out anterior si aplica
    if (AudioComponentMusicaNivel && AudioComponentMusicaNivel->IsPlaying())
    {
        AudioComponentMusicaNivel->FadeOut(2.0f, 0.0f);
    }

    // Crear manualmente un nuevo AudioComponent
    AudioComponentMusicaNivel = NewObject<UAudioComponent>(this); // <-- se crea correctamente dentro del UObject

    if (!AudioComponentMusicaNivel)
    {
      
        return;
    }

    AudioComponentMusicaNivel->RegisterComponent(); // MUY IMPORTANTE
    AudioComponentMusicaNivel->bAutoActivate = false;
    AudioComponentMusicaNivel->SetSound(Musica);
    AudioComponentMusicaNivel->bIsUISound = true;
    AudioComponentMusicaNivel->bAllowSpatialization = false;
    AudioComponentMusicaNivel->VolumeMultiplier = 0.25f;
    AudioComponentMusicaNivel->Play();

 
}
TScriptInterface<IIBuilderEscenario> UGestorEscenarios::GetBuilderInterfaceFromActor(AActor* Actor)
{
	if (Actor && Actor->GetClass()->ImplementsInterface(UIBuilderEscenario::StaticClass()))
	{
		TScriptInterface<IIBuilderEscenario> Interface;
		Interface.SetObject(Actor);
		Interface.SetInterface(Cast<IIBuilderEscenario>(Actor));
		return Interface;
	}
	return nullptr;
}
