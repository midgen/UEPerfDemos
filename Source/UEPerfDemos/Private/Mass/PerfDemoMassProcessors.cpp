#include "Mass/PerfDemoMassProcessors.h"

#include "UEPerfDemos.h"

#include "MassCommonTypes.h"
#include "UEPerfFunction.h"

#include "Mass/PerfDemoMassFragments.h"

DECLARE_CYCLE_STAT(TEXT("UEPerfDemo UpdateMoveTarget_Mass"), STAT_PerfDemoUpdateMoveTarget_Mass, STATGROUP_PerfDemo);
DECLARE_CYCLE_STAT(TEXT("UEPerfDemo UpdateVelocity_Mass"),   STAT_PerfDemoUpdateVelocity_Mass,   STATGROUP_PerfDemo);
DECLARE_CYCLE_STAT(TEXT("UEPerfDemo UpdateMovement_Mass"),   STAT_PerfDemoUpdateMovement_Mass, STATGROUP_PerfDemo);

UPerfDemoMoveTargetProcessor::UPerfDemoMoveTargetProcessor()
	: EntityQuery(*this)
{
	ExecutionFlags = (int32)(EProcessorExecutionFlags::All);
	ExecutionOrder.ExecuteInGroup = UE::Mass::ProcessorGroupNames::Tasks;
	ExecutionOrder.ExecuteAfter.Add(UE::Mass::ProcessorGroupNames::Behavior);
}

void UPerfDemoMoveTargetProcessor::ConfigureQueries()
{
	EntityQuery.AddRequirement<FPerfDemoMassFragment_Location>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddRequirement<FPerfDemoMassFragment_MoveTarget>(EMassFragmentAccess::ReadWrite);
}

void UPerfDemoMoveTargetProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	const float CurrentTime = GetWorld()->GetTimeSeconds();

	EntityQuery.ForEachEntityChunk(EntityManager, Context, [this, &EntityManager, CurrentTime, World = EntityManager.GetWorld()](FMassExecutionContext& Context)
	{
		const int32 NumEntities = Context.GetNumEntities();
		const TConstArrayView<FPerfDemoMassFragment_Location> LocationList = Context.GetFragmentView<FPerfDemoMassFragment_Location>();
		const TArrayView<FPerfDemoMassFragment_MoveTarget> MoveTargetList = Context.GetMutableFragmentView<FPerfDemoMassFragment_MoveTarget>();

		for (int32 i = 0; i < NumEntities; ++i)
		{
			
			const FPerfDemoMassFragment_Location& Location = LocationList[i];
			FPerfDemoMassFragment_MoveTarget& MoveTarget = MoveTargetList[i];
			
			SCOPE_CYCLE_COUNTER(STAT_PerfDemoUpdateMoveTarget_Mass)
			{
				UEPerf_Functions::UpdateMoveTarget(Location.Location, MoveTarget.MoveTarget);
			}
		}
		
	});
}

//**********************************

UPerfDemoVelocityProcessor::UPerfDemoVelocityProcessor()
	: EntityQuery(*this)
{
	ExecutionFlags = (int32)(EProcessorExecutionFlags::All);
	ExecutionOrder.ExecuteInGroup = UE::Mass::ProcessorGroupNames::Tasks;
	ExecutionOrder.ExecuteAfter.Add(UE::Mass::ProcessorGroupNames::Behavior);
}

void UPerfDemoVelocityProcessor::ConfigureQueries()
{
	EntityQuery.AddRequirement<FPerfDemoMassFragment_MoveTarget>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddRequirement<FPerfDemoMassFragment_Location>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddRequirement<FPerfDemoMassFragment_Velocity>(EMassFragmentAccess::ReadWrite);
}

void UPerfDemoVelocityProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	const float CurrentTime = GetWorld()->GetTimeSeconds();

	EntityQuery.ForEachEntityChunk(EntityManager, Context, [this, &EntityManager, CurrentTime, World = EntityManager.GetWorld()](FMassExecutionContext& Context)
	{
		const int32 NumEntities = Context.GetNumEntities();
		const TConstArrayView<FPerfDemoMassFragment_MoveTarget> MoveTargetList = Context.GetFragmentView<FPerfDemoMassFragment_MoveTarget>();
		const TConstArrayView<FPerfDemoMassFragment_Location> LocationList = Context.GetFragmentView<FPerfDemoMassFragment_Location>();
		const TArrayView<FPerfDemoMassFragment_Velocity> VelocityList = Context.GetMutableFragmentView<FPerfDemoMassFragment_Velocity>();

		for (int32 i = 0; i < NumEntities; ++i)
		{
			const FPerfDemoMassFragment_MoveTarget& MoveTarget = MoveTargetList[i];
			const FPerfDemoMassFragment_Location& Location = LocationList[i];
			FPerfDemoMassFragment_Velocity& Velocity = VelocityList[i];

			SCOPE_CYCLE_COUNTER(STAT_PerfDemoUpdateVelocity_Mass)
			{
				UEPerf_Functions::UpdateVelocity( MoveTarget.MoveTarget, Location.Location, Velocity.Velocity);
			}
		}
	});
}

//**********************************

UPerfDemoMovementProcessor::UPerfDemoMovementProcessor()
	: EntityQuery(*this)
{
	ExecutionFlags = (int32)(EProcessorExecutionFlags::All);
	ExecutionOrder.ExecuteInGroup = UE::Mass::ProcessorGroupNames::Tasks;
	ExecutionOrder.ExecuteAfter.Add(UE::Mass::ProcessorGroupNames::Behavior);
}

void UPerfDemoMovementProcessor::ConfigureQueries()
{
	EntityQuery.AddRequirement<FPerfDemoMassFragment_Velocity>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddRequirement<FPerfDemoMassFragment_Location>(EMassFragmentAccess::ReadWrite);
}

void UPerfDemoMovementProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	const float CurrentTime = GetWorld()->GetTimeSeconds();

	EntityQuery.ForEachEntityChunk(EntityManager, Context, [this, &EntityManager, CurrentTime, World = EntityManager.GetWorld()](FMassExecutionContext& Context)
	{
		const int32 NumEntities = Context.GetNumEntities();
		const TConstArrayView<FPerfDemoMassFragment_Velocity> VelocityList = Context.GetFragmentView<FPerfDemoMassFragment_Velocity>();
		const TArrayView<FPerfDemoMassFragment_Location> LocationList = Context.GetMutableFragmentView<FPerfDemoMassFragment_Location>();
		const float WorldDeltaTime = Context.GetDeltaTimeSeconds();

		for (int32 i = 0; i < NumEntities; ++i)
		{
			
			FPerfDemoMassFragment_Location& Location = LocationList[i];
			const FPerfDemoMassFragment_Velocity& Velocity = VelocityList[i];

			SCOPE_CYCLE_COUNTER(STAT_PerfDemoUpdateMovement_Mass)
			{
				UEPerf_Functions::UpdateMovement( Velocity.Velocity, WorldDeltaTime, Location.Location);
			}
		}
	});
}