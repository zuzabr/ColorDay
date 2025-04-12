// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "BTTask_NativeColorNPC.generated.h"

class ANPCCharacter;
class AColorDetourCrowdAIController;

UCLASS()
class COLORDAY_API UBTTask_NativeColorNPC : public UBTTask_BlueprintBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "NativeNPCTask")
	void NativeNPCExecuteTask();

	virtual void NativeNPCExecuteTask_Implementation();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Owning Character")
	ANPCCharacter* NPCCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Controller")
	AColorDetourCrowdAIController* AIController;
	
};
