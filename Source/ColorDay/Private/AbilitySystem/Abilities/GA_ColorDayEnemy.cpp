// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/Abilities/GA_ColorDayEnemy.h"
#include "NPC/NPCCharacter.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"

ANPCCharacter* UGA_ColorDayEnemy::GetNPC()
{
	if (!CachedNPC.IsValid())
	{
		CachedNPC = Cast<ANPCCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedNPC.IsValid() ? CachedNPC.Get() : nullptr;
}

UEnemyCombatComponent* UGA_ColorDayEnemy::GetCombatComponent() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UEnemyCombatComponent>();
}

FGameplayEffectSpecHandle UGA_ColorDayEnemy::MakeEnemyDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float WeaponDamage, FGameplayTag ColorTag)
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
