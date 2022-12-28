#pragma once


namespace UEPerf_Functions
{
	
	void UpdateMoveTarget(const FVector& InCurrentLocation, FVector& OutMoveTarget);

	
	void UpdateVelocity(const FVector& InMoveTarget, const FVector& InLocation, FVector& OutVelocity);

	
	void UpdateMovement(const FVector& InVelocity, const float InDeltaSeconds, FVector& OutLocation);
}