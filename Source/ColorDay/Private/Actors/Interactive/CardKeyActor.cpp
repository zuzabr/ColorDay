// ZuzabrGames All rights reserved 2024


#include "Actors/Interactive/CardKeyActor.h"
#include "ColorDayGameplayTags.h"
#include "Actors/ASC_ColorActor.h"
#include "Actors/Interactive/DoorActor.h"

void ACardKeyActor::UnlockAssignedDoor()
{

	if (!AssignedDoor) return;	
	AssignedDoor->GetColorDayAbilitySystemComp()->RemoveLooseGameplayTag(ColorDayGameplayTags::ColorActor_Status_Locked, 1);

}
