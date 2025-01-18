// ZuzabrGames All rights reserved 2024


#include "Actors/Interactive/InteractiveActor.h"
#include "Actors/ASC_ColorActor.h"

void AInteractiveActor::TryToHitItem(const FGameplayTag& ColorTag) const
{
	GetColorDayAbilitySystemComp()->ActivateAbility(ColorTag);
}

void AInteractiveActor::TryToInteractWithItem(const FGameplayTag& ColorTag) const
{
	GetColorDayAbilitySystemComp()->ActivateAbility(ColorTag);
}
