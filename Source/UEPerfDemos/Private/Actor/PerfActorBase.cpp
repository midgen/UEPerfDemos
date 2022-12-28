#include "Actor/PerfActorBase.h"

#include "UEPerfFunction.h"

namespace PerfActor_Private
{
	static const FName PerfActorComponentName = TEXT("PerfActorComponent");
}

APerfActorBase::APerfActorBase(const FObjectInitializer& InInitialiser)
	: Super(InInitialiser)
, PerfActorComponent(CreateDefaultSubobject<UPerfActorComponent>(PerfActor_Private::PerfActorComponentName))
{
	
}

