// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/DA_EnemyAbilities.h"
#include "AbilitySystem/Abilities/GA_ColorDayEnemy.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"

void UDA_EnemyAbilities::GiveToAbilitySystemComponent(UColorDayAbilitySystemComp* InASC, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASC, ApplyLevel);

	if (!EnemyAbilities.IsEmpty())
	{
		for (const TSubclassOf < UGA_ColorDayEnemy >& AbilityClass : EnemyAbilities)
		{
			if (!AbilityClass) continue;

			FGameplayAbilitySpec AbilitySpec(AbilityClass);
			AbilitySpec.SourceObject = InASC->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;

			InASC->GiveAbility(AbilitySpec);
		}
	}
}
