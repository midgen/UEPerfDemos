#include "UEPerfFunction.h"

namespace PerfFunction_Private
{
	static constexpr float MoveCompleteRange = 50.f;
	static constexpr float MoveCompleteRange2 = MoveCompleteRange * MoveCompleteRange;
	static constexpr float MoveTargetRange = 5000.f;
	static constexpr float MoveSpeed = 1000.f;
}

void UEPerf_Functions::UpdateMoveTarget(const FVector& CurrentLocation, FVector& MoveTarget)
{
	if(FVector::DistSquared2D(CurrentLocation, MoveTarget) < PerfFunction_Private::MoveCompleteRange2)
	{
		MoveTarget.X = FMath::RandRange(-PerfFunction_Private::MoveTargetRange, PerfFunction_Private::MoveTargetRange);
		MoveTarget.Y = FMath::RandRange(-PerfFunction_Private::MoveTargetRange, PerfFunction_Private::MoveTargetRange);
	}
}

void UEPerf_Functions::UpdateVelocity(const FVector& InMoveTarget, const FVector& InLocation, FVector& OutVelocity)
{
	OutVelocity = (InMoveTarget - InLocation).GetSafeNormal2D() * PerfFunction_Private::MoveSpeed;
}

void UEPerf_Functions::UpdateMovement(const FVector& Velocity, const float DeltaSeconds, FVector& OutLocation)
{
	OutLocation+= (Velocity * DeltaSeconds);
}
