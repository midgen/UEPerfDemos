// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/PerfActorComponent.h"

#include "UEPerfDemos.h"

#include "UEPerfFunction.h"

DECLARE_CYCLE_STAT(TEXT("UEPerfDemo UpdateMoveTarget"), STAT_PerfDemoUpdateMoveTarget, STATGROUP_PerfDemo);
DECLARE_CYCLE_STAT(TEXT("UEPerfDemo UpdateVelocity"),   STAT_PerfDemoUpdateVelocity,   STATGROUP_PerfDemo);
DECLARE_CYCLE_STAT(TEXT("UEPerfDemo UpdateMovement"),   STAT_PerfDemoUpdateMovement, STATGROUP_PerfDemo);

// Sets default values for this component's properties
UPerfActorComponent::UPerfActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPerfActorComponent::BeginPlay()
{
	Super::BeginPlay();

	Location = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UPerfActorComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	SCOPE_CYCLE_COUNTER(STAT_PerfDemoUpdateMoveTarget)
	{
		UEPerf_Functions::UpdateMoveTarget(Location, MoveTarget);
	}
	SCOPE_CYCLE_COUNTER(STAT_PerfDemoUpdateVelocity)
	{
		UEPerf_Functions::UpdateVelocity(MoveTarget, Location, Velocity);
	}
	SCOPE_CYCLE_COUNTER(STAT_PerfDemoUpdateMovement)
	{
		UEPerf_Functions::UpdateMovement(Velocity, DeltaTime, Location);
	}

	GetOwner()->SetActorLocation(Location);
}

