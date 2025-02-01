// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/Abilities/ColorDayGameplayAbility.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"
#include "Components/CombatComponent.h"
#include "ColorDayDebugHelper.h"
#include "ColorDay/ColorDayCharacter.h"
#include "ColorDayGameplayTags.h"


void UColorDayGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == EColorDayAbilityActivationPolicy::OnGiven)
	{
		if(ActorInfo&& !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UColorDayGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (AbilityActivationPolicy == EColorDayAbilityActivationPolicy::OnGiven)
	{
		ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
	}
}

UColorDayAbilitySystemComp* UColorDayGameplayAbility::GetColorColorDayAbilitySystemComp() const
{
	return Cast<UColorDayAbilitySystemComp>(CurrentActorInfo->AbilitySystemComponent);
}

FActiveGameplayEffectHandle UColorDayGameplayAbility::NativeApplyEffectSpecHandleToSelf(const FGameplayEffectSpecHandle& SpecHandle)
{
	check(SpecHandle.IsValid());
	return GetColorColorDayAbilitySystemComp()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data);
	
}

FActiveGameplayEffectHandle UColorDayGameplayAbility::BP_ApplyEffectSpecHandleToSelf(const FGameplayEffectSpecHandle& SpecHandle)
{
	return NativeApplyEffectSpecHandleToSelf(SpecHandle);

}