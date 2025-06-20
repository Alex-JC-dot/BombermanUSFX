// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeLevel2.h"

#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
 
AGameModeLevel2::AGameModeLevel2()
{
    PrimaryActorTick.bCanEverTick = true;
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
  
}

void AGameModeLevel2::BeginPlay()
{
    Super::BeginPlay();
    Director =GetWorld()->SpawnActor<ADirector>(ADirector::StaticClass());
    BuilderHielo =GetWorld()->SpawnActor<ABuilderHielo>(ABuilderHielo::StaticClass());

    Director->LlamarConstructor(BuilderHielo);
    Director->ConstruirLaberinto();
    ALaberintoTerminado* Laberinto = Director->GetLaberinto();

};
