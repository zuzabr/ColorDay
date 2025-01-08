// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/DA_StartupHeroAbilities.h"
#include "AbilitySystem/Abilities/ColorDayGameplayAbility.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"
#include "ColorDayCoreTypes.h"

void UDA_StartupHeroAbilities::GiveToAbilitySystemComponent(UColorDayAbilitySystemComp* InASC, int32 ApplyLevel)
{
	check(InASC);
	GrantAbilities(ActivateOnGivenAbilities, InASC, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASC, ApplyLevel);

	for (const FPlayerAbilitySet& AbilitySet : PlayerStartAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASC->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASC->GiveAbility(AbilitySpec);
	}
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


