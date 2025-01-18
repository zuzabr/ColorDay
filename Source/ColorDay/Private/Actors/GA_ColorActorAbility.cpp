// ZuzabrGames All rights reserved 2024


#include "Actors/GA_ColorActorAbility.h"
#include "Actors/ColorDayActor.h"
#include "Actors/ASC_ColorActor.h"

AColorDayActor* UGA_ColorActorAbility::GetColorDayActor()
{
	if (!CachedColorActor.IsValid())
	{
		CachedColorActor = Cast<AColorDayActor>(CurrentActorInfo->AvatarActor);
	}

	return CachedColorActor.IsValid() ? CachedColorActor.Get() : nullptr;
}

UASC_ColorActor* UGA_ColorActorAbility::GetColorColorDayAbilitySystemComp() const
{
	return Cast<UASC_ColorActor>(CurrentActorInfo->AbilitySystemComponent);
}
