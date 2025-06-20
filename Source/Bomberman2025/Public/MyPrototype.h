#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyPrototype.generated.h"

UINTERFACE(MinimalAPI)
class UMyPrototype : public UInterface
{
	GENERATED_BODY()
};

class BOMBERMAN2025_API IMyPrototype
{
	GENERATED_BODY()

public:
	

	virtual IMyPrototype* Clone() = 0;
};