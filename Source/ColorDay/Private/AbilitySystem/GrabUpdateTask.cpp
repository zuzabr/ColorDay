// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/GrabUpdateTask.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "ColorDay/ColorDayCharacter.h"
#include "Camera/CameraComponent.h"
#include "TimerManager.h"


UGrabUpdateTask* UGrabUpdateTask::CreateGrabUpdateTask(UGameplayAbility* OwningAbility, UPhysicsHandleComponent* Handle, AColorDayCharacter* Owner, float UpdateInterval)
{
    UGrabUpdateTask* Task = NewAbilityTask<UGrabUpdateTask>(OwningAbility);
    Task->PhysicsHandle = Handle;
    Task->OwnerActor = Owner;
    Task->Interval = UpdateInterval;
    

    return Task;
}

void UGrabUpdateTask::Activate()
{
    Camera = OwnerActor->GetFirstPersonCameraComponent();

    if (!PhysicsHandle || !OwnerActor||!Camera)
    {
        EndTask();
        return;
    }
    
    

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().SetTimer(TimerHandle, this, &UGrabUpdateTask::UpdateGrabPosition, Interval, true);
    }
}

void UGrabUpdateTask::UpdateGrabPosition()
{
    if (!PhysicsHandle || !OwnerActor||!Camera)
    {
        EndTask();
        return;
    }

    FVector CameraLocation = Camera->GetComponentLocation();
    FVector CameraForward = Camera->GetForwardVector();


    FVector TargetLocation = CameraLocation + (CameraForward * 200.0f);
    PhysicsHandle->SetTargetLocation(TargetLocation);
}

void UGrabUpdateTask::StopUpdating()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(TimerHandle);
    }

   EndTask();

}
