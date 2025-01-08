// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/ColorDayAbilitySystemComp.h"
#include "AbilitySystem/Abilities/ColorDayGameplayAbility.h"

void UColorDayAbilitySystemComp::OnAbilityInputPressed(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UColorDayAbilitySystemComp::OnAbilityInputReleased(const FGameplayTag& InputTag)
{
}

void UColorDayAbilitySystemComp::GrantPlayerWeaponAbilities(const TArray<FPlayerAbilitySet>& Abilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& GrantedAbilitySpecHandles)
{
	if (Abilities.IsEmpty()) return;

	for (const FPlayerAbilitySet& Ability : Abilities)
	{
		if (!Ability.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(Ability.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(Ability.InputTag);

		GrantedAbilitySpecHandles.AddUnique(GiveAbility(AbilitySpec));
	}
}

void UColorDayAbilitySystemComp::RemovePlayerWeaponAbilities(UPARAM(ref)TArray<FGameplayAbilitySpecHandle>& AbilitySpecHandlesToRemove)
{
	if (AbilitySpecHandlesToRemove.IsEmpty()) return;

	for (const FGameplayAbilitySpecHandle& SpecHandle : AbilitySpecHandlesToRemove)
	{
		if (SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}
	}

	AbilitySpecHandlesToRemove.Empty();
}
