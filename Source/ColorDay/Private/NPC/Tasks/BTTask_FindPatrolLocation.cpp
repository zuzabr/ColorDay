// ZuzabrGames All rights reserved 2024


#include "NPC/Tasks/BTTask_FindPatrolLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "NPC/NPCCharacter.h"
#include "Actors/PatrolSplineActor.h"

UBTTask_FindPatrolLocation::UBTTask_FindPatrolLocation()
{
	NodeName = "Set Location on Spline";
}

EBTNodeResult::Type UBTTask_FindPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    
 // Check the pointers   
    const auto AIController = OwnerComp.GetAIOwner();
    if (!AIController) return EBTNodeResult::Failed;

    const auto NPCCharacter = Cast<ANPCCharacter>(AIController->GetPawn());
    if (!NPCCharacter) return EBTNodeResult::Failed;

    const auto Spline = NPCCharacter->GetPatrolPath();
    if (!Spline) return EBTNodeResult::Failed;
    
    auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    if(!BlackboardComp) return EBTNodeResult::Failed;

// Get Location for current index
    FVector TargetLocation = Spline->GetCurrentPointLocation();
//Set Location for current index
    BlackboardComp->SetValueAsVector(TargetLocationKey.SelectedKeyName, TargetLocation);  
// Increment Point Index On Path
    Spline->GoToNextPoint(bLoopedPath);

    return EBTNodeResult::Succeeded;

}
