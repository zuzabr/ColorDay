// ZuzabrGames All rights reserved 2024


#include "NPC/Tasks/BTTask_NativeColorNPC.h"
#include "NPC/ColorDetourCrowdAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC/NPCCharacter.h"



EBTNodeResult::Type UBTTask_NativeColorNPC::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    if (NPCCharacter)
    {
        NativeNPCExecuteTask();
        return EBTNodeResult::Succeeded;
    }
    if (!AIController)
    {
        AIController = Cast<AColorDetourCrowdAIController>(OwnerComp.GetAIOwner());
    }
   
    if (!AIController) return EBTNodeResult::Failed;

    NPCCharacter = Cast<ANPCCharacter>(AIController->GetPawn());
    if (!NPCCharacter) return EBTNodeResult::Failed;

    NativeNPCExecuteTask();
    return EBTNodeResult::Succeeded;
}

void UBTTask_NativeColorNPC::NativeNPCExecuteTask_Implementation()
{
}
