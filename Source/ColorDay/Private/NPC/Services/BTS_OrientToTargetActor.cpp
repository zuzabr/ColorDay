// ZuzabrGames All rights reserved 2024


#include "NPC/Services/BTS_OrientToTargetActor.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"

UBTS_OrientToTargetActor::UBTS_OrientToTargetActor()
{
	NodeName = TEXT("Native Orient Rotation to Target Actor");

	INIT_SERVICE_NODE_NOTIFY_FLAGS();

	RotationInterpSpeed = 5.f;
	Interval = 0.f;
	RandomDeviation = 0.f;

	TargetActorKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, TargetActorKey), AActor::StaticClass());
}

void UBTS_OrientToTargetActor::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);

	if (const auto BBAsset = GetBlackboardAsset())
	{
		TargetActorKey.ResolveSelectedKey(*BBAsset);
	}
}

FString UBTS_OrientToTargetActor::GetStaticDescription() const
{
	const auto KeyDescription = TargetActorKey.SelectedKeyName.ToString();
	return FString::Printf(TEXT("Orient rotation to %s Key %s"), *KeyDescription, *GetStaticServiceDescription());

}

void UBTS_OrientToTargetActor::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	const auto ActorObject = OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetActorKey.SelectedKeyName);
	const auto TargetActor = Cast<AActor>(ActorObject);
	
	const auto OwningPawn = OwnerComp.GetAIOwner()->GetPawn();

	if (OwningPawn && TargetActor)
	{
		const auto LookAtRot = UKismetMathLibrary::FindLookAtRotation(OwningPawn->GetActorLocation(), TargetActor->GetActorLocation());
		const auto TargetRot = FMath::RInterpTo(OwningPawn->GetActorRotation(), LookAtRot, DeltaSeconds, RotationInterpSpeed);

		OwningPawn->SetActorRotation(TargetRot);
	}
}
