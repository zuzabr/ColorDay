// ZuzabrGames All rights reserved 2024


#include "Components/CombatComponent.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"


void UCombatComponent::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& SpecHandles)
{
	GrantedAbilitySpecHandles = SpecHandles;
}

TArray<FGameplayAbilitySpecHandle> UCombatComponent::GetGrantedAbilitySpecHandles() const
{
	return GrantedAbilitySpecHandles;
}

void UCombatComponent::OnHitTargetActor(AActor* HitActor)
{
}

void UCombatComponent::OnHitByActor(AActor* InstigatorActor)
{
}






