#include "MyGameInstance.h"
#include "UObject/ConstructorHelpers.h"

UMyGameInstance::UMyGameInstance()
{
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPlayerPawn = PlayerPawnBPClass.Class;
    }
}