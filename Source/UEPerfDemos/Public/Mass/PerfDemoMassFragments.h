#pragma once

#include "MassEntityTypes.h"
#include "PerfDemoMassFragments.generated.h"

USTRUCT()
struct FPerfDemoMassFragment_Location : public FMassFragment
{
	GENERATED_BODY()

	FVector Location;
};

USTRUCT()
struct FPerfDemoMassFragment_MoveTarget : public FMassFragment
{
	GENERATED_BODY()

	FVector MoveTarget;
};

USTRUCT()
struct FPerfDemoMassFragment_Velocity : public FMassFragment
{
	GENERATED_BODY()

	FVector Velocity;
};