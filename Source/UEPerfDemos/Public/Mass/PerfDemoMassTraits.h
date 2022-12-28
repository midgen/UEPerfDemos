

#include "MassEntityTraitBase.h"

#include "PerfDemoMassTraits.generated.h"

UCLASS(meta=(DisplayName="PerfDemoRandomMovement"))
class UMassRandomMovementTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()
public:

	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;
};

