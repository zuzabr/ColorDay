// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/Abilities/GA_ColorDayPlayer.h"
#include "ColorDay/ColorDayCharacter.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"
#include "ColorDayGameplayTags.h"

AColorDayCharacter* UGA_ColorDayPlayer::GetColorDayCharacter()
{
	if (!CachedCharacter.IsValid())
	{
		CachedCharacter = Cast<AColorDayCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedCharacter.IsValid() ? CachedCharacter.Get() : nullptr;

}

AColorDayPlayerController* UGA_ColorDayPlayer::GetColorController()
{
	if (!CachedController.IsValid())
	{
		CachedController = Cast<AColorDayPlayerController>(CurrentActorInfo->PlayerController);
	}

	return CachedController.IsValid() ? CachedController.Get() : nullptr;
}

UPlayerCombatComponent* UGA_ColorDayPlayer::GetCombatComponent() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPlayerCombatComponent>();
}

FGameplayEffectSpecHandle UGA_ColorDayPlayer::MakePlayerDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, const FScalableFloat& InDamageScalableFloat)
{
	if(!EffectClass) return FGameplayEffectSpecHandle();

	FGameplayEffectContextHandle ContextHandle = GetColorColorDayAbilitySystemComp()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(),GetAvatarActorFromActorInfo());

	FGameplayEffectSpecHandle EffectSpecHandle = GetColorColorDayAbilitySystemComp()->MakeOutgoingSpec(
		EffectClass,
		GetAbilityLevel(),
		ContextHandle
	);

	EffectSpecHandle.Data->SetSetByCallerMagnitude(
		ColorDayGameplayTags::Shared_Damage,
		InDamageScalableFloat.GetValueAtLevel(GetAbilityLevel())
	);

	return EffectSpecHandle;
}