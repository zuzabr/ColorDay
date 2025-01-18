
#include "ColorDayCoreTypes.h"
#include "AbilitySystem/Abilities/ColorDayGameplayAbility.h"

bool FPlayerAbilitySet::IsValid() const
{
    return InputTag.IsValid() && AbilityToGrant;
}

bool FColorActorAbilitySet::IsValid() const
{
    return ColorTag.IsValid() && AbilityToGrant;
}
