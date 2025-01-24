// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "GrabUpdateTask.generated.h"

class UPhysicsHandleComponent;
class AColorDayCharacter;
class UCameraComponent;

UCLASS()
class COLORDAY_API UGrabUpdateTask : public UAbilityTask
{
	GENERATED_BODY()

public:

   
    UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (DisplayName = "Update Grab Location", BlueprintInternalUseOnly = "true"))
    static UGrabUpdateTask* CreateGrabUpdateTask(UGameplayAbility* OwningAbility, UPhysicsHandleComponent* Handle, AColorDayCharacter* Owner, float UpdateInterval = 0.01f);

protected:
    UFUNCTION(BlueprintCallable, Category = "Physics Handle Task")
    virtual void Activate() override;

    UFUNCTION(BlueprintCallable, Category = "Physics Handle Task")
    void StopUpdating();

private:
    void UpdateGrabPosition();


    UPROPERTY()
    UPhysicsHandleComponent* PhysicsHandle;

    UPROPERTY()
    AColorDayCharacter* OwnerActor;

    UPROPERTY()
    UCameraComponent* Camera;

    FTimerHandle TimerHandle;
    float Interval;
	
};
