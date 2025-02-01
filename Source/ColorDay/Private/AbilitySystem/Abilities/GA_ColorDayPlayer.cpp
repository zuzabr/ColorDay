// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/Abilities/GA_ColorDayPlayer.h"
#include "ColorDay/ColorDayCharacter.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"

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

FGameplayEffectSpecHandle UGA_ColorDayPlayer::MakePlayerDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float WeaponDamage, FGameplayTag ColorTag)
{
	check(EffectClass);
	auto ContextHandle = GetColorColorDayAbilitySystemComp()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());

	auto EffectSpecHandle = GetColorColorDayAbilitySystemComp()->MakeOutgoingSpec(
		EffectClass,
		GetAbilityLevel(),
		ContextHandle
	);

	if (ColorTag.IsValid())
	{
		EffectSpecHandle.Data->SetSetByCallerMagnitude(ColorTag, WeaponDamage);
	}


	return EffectSpecHandle;
}