// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/Abilities/ColorDayGameplayAbility.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"
#include "Components/CombatComponent.h"
#include "ColorDayDebugHelper.h"
#include "ColorDay/ColorDayCharacter.h"

AColorDayCharacter* UColorDayGameplayAbility::GetColorDayCharacter()
{
	if (!CachedCharacter.IsValid()) 
	{
		CachedCharacter = Cast<AColorDayCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedCharacter.IsValid() ? CachedCharacter.Get() : nullptr;
	
	
	
}

AColorDayPlayerController* UColorDayGameplayAbility::GetColorController()
{
	if (!CachedController.IsValid())
	{
		CachedController = Cast<AColorDayPlayerController>(CurrentActorInfo->PlayerController);		
	}

	return CachedController.IsValid() ? CachedController.Get() : nullptr;
}

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

UCombatComponent* UColorDayGameplayAbility::GetCombatComponent() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UCombatComponent>();
}

UColorDayAbilitySystemComp* UColorDayGameplayAbility::GetColorColorDayAbilitySystemComp() const
{
	return Cast<UColorDayAbilitySystemComp>(CurrentActorInfo->AbilitySystemComponent);
}
