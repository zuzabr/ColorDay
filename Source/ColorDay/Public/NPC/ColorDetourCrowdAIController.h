// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "DetourCrowdAIController.h"
#include "ColorDayCoreTypes.h"
#include "ColorDetourCrowdAIController.generated.h"

class UAIPerceptionComponent;
class UAISenseConfig_Sight;
class UAISenseConfig_Hearing;
class UAISenseConfig_Damage;

UCLASS()
class COLORDAY_API AColorDetourCrowdAIController : public ADetourCrowdAIController
{
	GENERATED_BODY()

public:
	AColorDetourCrowdAIController();

	//Override from UGenericTeamAgentInterface
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

protected:
	virtual void BeginPlay() override;

	virtual void OnUnPossess() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAIPerceptionComponent* EnemyPerceptionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAISenseConfig_Sight* AISenseConfig_Sight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAISenseConfig_Hearing* AISenseConfig_Hearing;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAISenseConfig_Damage* AISenseConfig_Damage;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ENPCState CurrentNPCState;


	

	UFUNCTION(BlueprintCallable, Category = "Perception")
	void ChangeCurrentNPCState(ENPCState StateToChangeTo, FGameplayTag TagToSet);

	virtual void OnSeeAnEnemy(AActor* Actor);
	virtual void OnHearAnEnemy(FVector Location);
	virtual void OnDamagedByAnEnemy(AActor* Actor);
	void ForgetAboutTarget();


	UFUNCTION(BlueprintCallable, Category = "Perception")
	virtual void OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	UFUNCTION(BlueprintCallable, Category = "Perception")
	virtual void OnEnemyLostTheTarget(AActor* ActorToForget, FVector LastSeenLocation);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Crowd Avoidance Config")
	bool bEnableDetourCrowdAvoidance = true;

	UPROPERTY(EditDefaultsOnly, Category = "Crowd Avoidance Config", meta = (EditCondition = "bEnableDetourCrowdAvoidance", UIMin = "1", UIMax = "4"))
	int32 DetourCrowdAvoidanceQuality = 4;

	UPROPERTY(EditDefaultsOnly, Category = "Crowd Avoidance Config", meta = (EditCondition = "bEnableDetourCrowdAvoidance"))
	float CollisionQueryRange = 600.f;

	FTimerHandle ForgetPlayerTimerHandle;
};
