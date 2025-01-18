// ZuzabrGames All rights reserved 2024


#include "Actors/ASC_ColorActor.h"

void UASC_ColorActor::ActivateAbility(const FGameplayTag& ColorTag)
{

	if (!ColorTag.IsValid()) return;

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(ColorTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}
