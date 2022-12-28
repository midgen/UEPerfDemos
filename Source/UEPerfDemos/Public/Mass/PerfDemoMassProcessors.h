#pragma once

#include "MassProcessor.h"

#include "PerfDemoMassProcessors.generated.h"

UCLASS()
class UPerfDemoMoveTargetProcessor : public UMassProcessor
{
	GENERATED_BODY()

	UPerfDemoMoveTargetProcessor();

protected:

	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

	FMassEntityQuery EntityQuery;
};

UCLASS()
class UPerfDemoVelocityProcessor : public UMassProcessor
{
	GENERATED_BODY()

	UPerfDemoVelocityProcessor();

protected:

	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

	FMassEntityQuery EntityQuery;
};

UCLASS()
class UPerfDemoMovementProcessor : public UMassProcessor
{
	GENERATED_BODY()

	UPerfDemoMovementProcessor();

protected:

	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

	FMassEntityQuery EntityQuery;
};

