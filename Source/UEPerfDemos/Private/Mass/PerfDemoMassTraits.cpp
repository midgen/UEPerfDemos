#include "Mass/PerfDemoMassTraits.h"
#include "Mass/PerfDemoMassFragments.h"

#include <MassSpawner/Public/MassEntityTemplateRegistry.h>

void UMassRandomMovementTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext,
                                                    const UWorld& World) const
{
	BuildContext.AddFragment<FPerfDemoMassFragment_Location>();
	BuildContext.AddFragment<FPerfDemoMassFragment_MoveTarget>();
	BuildContext.AddFragment<FPerfDemoMassFragment_Velocity>();
};
