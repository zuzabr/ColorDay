// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/DA_PlayerAbilities.h"
#include "Actors/GA_ColorActorAbility.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"

void UDA_PlayerAbilities::GiveToAbilitySystemComponent(UColorDayAbilitySystemComp* InASC, int32 ApplyLevel)
{
    Super::GiveToAbilitySystemComponent(InASC, ApplyLevel);

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
