// ZuzabrGames All rights reserved 2024


#include "NPC/DA_EmemyAbilities.h"

#include "AbilitySystem/Abilities/ColorDayGameplayAbility.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"
#include "ColorDayCoreTypes.h"

void UDA_EmemyAbilities::GiveToAbilitySystemComponent(UColorDayAbilitySystemComp* InASC, int32 ApplyLevel)
{
	check(InASC);
	GrantAbilities(ActivateOnGivenAbilities, InASC, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASC, ApplyLevel);

	if (!EnemyAbilities.IsEmpty())
	{
		for(const TSubclassOf<UColorDayGameplayAbility>& Ability: EnemyAbilities)
		{
			if (!Ability) continue;

			FGameplayAbilitySpec AbilitySpec(Ability);
			AbilitySpec.SourceObject = InASC->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;

			InASC->GiveAbility(AbilitySpec);
		}
	}

	if (!StartUpGameplayEffects.IsEmpty())
	{
		for (const TSubclassOf<UGameplayEffect>& EffectClass : StartUpGameplayEffects)
		{
			if (!EffectClass) continue;

			UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();
			InASC->ApplyGameplayEffectToSelf(EffectCDO, ApplyLevel, InASC->MakeEffectContext());
		}
	}
}

void UDA_EmemyAbilities::GrantAbilities(const TArray<TSubclassOf<UColorDayGameplayAbility>>& AbilitiesToGive, UColorDayAbilitySystemComp* InASC, int32 ApplyLevel)
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