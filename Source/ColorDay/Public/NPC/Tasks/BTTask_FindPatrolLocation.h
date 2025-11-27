// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindPatrolLocation.generated.h"

/**
 * 
 */
UCLASS()
class COLORDAY_API UBTTask_FindPatrolLocation : public UBTTaskNode
{
	GENERATED_BODY()

public:
    UBTTask_FindPatrolLocation();

protected:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:

    UPROPERTY(EditAnywhere, Category = "Blackboard")
    FBlackboardKeySelector TargetLocationKey;

    UPROPERTY(EditAnywhere, Category = "Blackboard")
    bool bLoopedPath = false;


	
};
