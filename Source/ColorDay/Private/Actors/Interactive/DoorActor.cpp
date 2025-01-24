// ZuzabrGames All rights reserved 2024


#include "Actors/Interactive/DoorActor.h"
#include "ColorDayGameplayTags.h"
#include "Actors/ASC_ColorActor.h"

void ADoorActor::BeginPlay()
{
	Super::BeginPlay();

	if (bInitiallyLocked)
	{
		GetColorDayAbilitySystemComp()->AddLooseGameplayTag(ColorDayGameplayTags::ColorActor_Status_Locked, 1);
	}
}
