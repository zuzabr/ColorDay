
#include "ColorDayCoreTypes.h"
#include "AbilitySystem/Abilities/ColorDayGameplayAbility.h"

bool FPlayerAbilitySet::IsValid() const
{
    return InputTag.IsValid() && AbilityToGrant;
}
