// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/DA_StartupHeroAbilities.h"
#include "AbilitySystem/Abilities/ColorDayGameplayAbility.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"

void UDA_StartupHeroAbilities::GiveToAbilitySystemComponent(UColorDayAbilitySystemComp* InASC, int32 ApplyLevel)
{
	check(InASC);
	GrantAbilities(ActivateOnGivenAbilities, InASC, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASC, ApplyLevel);
}

void UDA_StartupHeroAbilities::GrantAbilities(const TArray<TSubclassOf<UColorDayGameplayAbility>>& AbilitiesToGive, UColorDayAbilitySystemComp* InASC, int32 ApplyLevel)
{
	if (AbilitiesToGive.IsEmpty()) return;

	for (const auto& Ability : AbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASC->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASC->GiveAbility(AbilitySpec);
	}
}
