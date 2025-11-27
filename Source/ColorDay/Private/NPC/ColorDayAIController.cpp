// ZuzabrGames All rights reserved 2024


#include "NPC/ColorDayAIController.h"
#include "Navigation/CrowdFollowingComponent.h"

AColorDayAIController::AColorDayAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>("PathFollowingComponent"))
{
}
