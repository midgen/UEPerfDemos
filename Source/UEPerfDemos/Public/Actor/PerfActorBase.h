
#pragma once

#include <Runtime\Engine\Classes\GameFramework\Actor.h>

#include "PerfActorComponent.h"
#include "PerfActorBase.generated.h"

UCLASS(Blueprintable)
class APerfActorBase : public AActor
{
	GENERATED_BODY()

public:
	explicit APerfActorBase(const FObjectInitializer& InInitialiser);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UPerfActorComponent> PerfActorComponent;
};