// ZuzabrGames All rights reserved 2024


#include "NPC/ColorDetourCrowdAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Damage.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionSystem.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "ColorDayDebugHelper.h"
#include "ColorDayFunctionLibrary.h"
#include "ColorDayGameplayTags.h"

AColorDetourCrowdAIController::AColorDetourCrowdAIController()
{
	EnemyPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("Perception Component");

//===========Perception Sight Config======================================
	AISenseConfig_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>("Sight Sense");
	AISenseConfig_Sight->DetectionByAffiliation.bDetectEnemies = true;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectFriendlies = false;
	AISenseConfig_Sight->DetectionByAffiliation.bDetectNeutrals = false;
	AISenseConfig_Sight->SightRadius = 1000.f;
	AISenseConfig_Sight->LoseSightRadius = 1500.f;
	AISenseConfig_Sight->PeripheralVisionAngleDegrees = 100.f;
	AISenseConfig_Sight->SetMaxAge(15.f);

//===========Perception Hearing Config======================================
	AISenseConfig_Hearing = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hearing Sense"));
	AISenseConfig_Hearing->HearingRange = 2000.f;
	AISenseConfig_Hearing->LoSHearingRange = 1500.f;
	AISenseConfig_Hearing->DetectionByAffiliation.bDetectEnemies = true;
	AISenseConfig_Hearing->DetectionByAffiliation.bDetectNeutrals = false;
	AISenseConfig_Hearing->DetectionByAffiliation.bDetectFriendlies = false;

//===========Perception DamagrConfig======================================
	AISenseConfig_Damage = CreateDefaultSubobject<UAISenseConfig_Damage>(TEXT("Damage Sense"));
	

	EnemyPerceptionComponent->ConfigureSense(*AISenseConfig_Sight);
	EnemyPerceptionComponent->ConfigureSense(*AISenseConfig_Hearing);
	EnemyPerceptionComponent->ConfigureSense(*AISenseConfig_Damage);
	EnemyPerceptionComponent->SetDominantSense(UAISenseConfig_Sight::StaticClass());
	EnemyPerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &ThisClass::OnEnemyPerceptionUpdated);


	SetGenericTeamId(FGenericTeamId(1));


// Set NPC State
	CurrentNPCState = ENPCState::Passive;
}

ETeamAttitude::Type AColorDetourCrowdAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const APawn* PawnToCheck = Cast<const APawn>(&Other);
	if (!PawnToCheck) return ETeamAttitude::Neutral;
	const IGenericTeamAgentInterface* OtherTeamAgent = Cast<const IGenericTeamAgentInterface>(PawnToCheck->GetController());

	if (OtherTeamAgent && OtherTeamAgent->GetGenericTeamId() < GetGenericTeamId())
	{
		return ETeamAttitude::Hostile;
	}

	return ETeamAttitude::Friendly;
}
void AColorDetourCrowdAIController::BeginPlay()
{
	Super::BeginPlay();

	if (auto CrowdComp = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()))
	{
		CrowdComp->SetCrowdSimulationState(bEnableDetourCrowdAvoidance ? ECrowdSimulationState::Enabled : ECrowdSimulationState::Disabled);

		switch (DetourCrowdAvoidanceQuality)
		{
		case 1: CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Low); break;
		case 2: CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Medium); break;
		case 3: CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Good); break;
		case 4: CrowdComp->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::High); break;
		default: break;
		}

		CrowdComp->SetAvoidanceGroup(1);
		CrowdComp->SetGroupsToAvoid(1);
		CrowdComp->SetCrowdCollisionQueryRange(CollisionQueryRange);
		
	}

}

void AColorDetourCrowdAIController::OnUnPossess()
{
	Super::OnUnPossess();
	Destroy();
}


void AColorDetourCrowdAIController::OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	
	auto SenseClass = UAIPerceptionSystem::GetSenseClassForStimulus(this, Stimulus);
	
//=================================================Check Sight Sense=============================================	
	if (SenseClass->IsChildOf(UAISense_Sight::StaticClass()))
	{		
		if (Stimulus.WasSuccessfullySensed()&&GetWorld())
		{
			GetWorld()->GetTimerManager().ClearTimer(ForgetPlayerTimerHandle);
			OnSeeAnEnemy(Actor);
		}
		else if (!Stimulus.WasSuccessfullySensed() && GetWorld())
		{			
			OnEnemyLostTheTarget(Actor, Stimulus.StimulusLocation);
			GetWorld()->GetTimerManager().SetTimer(ForgetPlayerTimerHandle, this, &AColorDetourCrowdAIController::ForgetAboutTarget, AISenseConfig_Sight->GetMaxAge(),false);			
		}
		
	}

//=================================================Check Hearing Sense=============================================	
	else if (SenseClass->IsChildOf(UAISense_Hearing::StaticClass()))
	{
		
		if (Stimulus.WasSuccessfullySensed())
		{
			OnHearAnEnemy(Stimulus.StimulusLocation);
		}

		else if (!Stimulus.WasSuccessfullySensed())
		{
			OnEnemyLostTheTarget(Actor, Stimulus.StimulusLocation);
		}
	}

//=================================================Check Hearing Sense=============================================	
	else if (SenseClass->IsChildOf(UAISense_Damage::StaticClass()))
	{
		
		
		if (Stimulus.WasSuccessfullySensed())
		{
			OnDamagedByAnEnemy(Actor);
		}
		else if (!Stimulus.WasSuccessfullySensed())
		{
			OnEnemyLostTheTarget(Actor, Stimulus.StimulusLocation);
		}
	}
	else
	{
		Debug::Print(TEXT("Have a realy strange feeling : "), Actor);
	}
			
}

void AColorDetourCrowdAIController::OnEnemyLostTheTarget(AActor* LostActor, FVector LastSeenLocation)
{
	
	
	if (UBlackboardComponent* BBComponent = GetBlackboardComponent())
	{		
		BBComponent->SetValueAsVector(FName("PointOfInterest"), LastSeenLocation);
	}

	
}

void AColorDetourCrowdAIController::OnSeeAnEnemy(AActor* Actor)
{
	if (UBlackboardComponent* BBComponent = GetBlackboardComponent())
	{
		if (!BBComponent->GetValueAsObject(FName("TargetActor")) && Actor)
		{
			BBComponent->SetValueAsObject(FName("TargetActor"), Actor);

		}
	}

	switch (CurrentNPCState)
	{
	case ENPCState::Passive:

		ChangeCurrentNPCState(ENPCState::Attack, ColorDayGameplayTags::NPC_State_Attack);
		break;

	case ENPCState::Attack:
		break;
	case ENPCState::Investigate:
		ChangeCurrentNPCState(ENPCState::Attack, ColorDayGameplayTags::NPC_State_Attack);
		break;
	case ENPCState::Staggered:
		break;
	case ENPCState::Dead:
		break;
	default:
		break;
	}
	
}

void AColorDetourCrowdAIController::OnHearAnEnemy(FVector Location)
{
	
	if (UBlackboardComponent* BBComponent = GetBlackboardComponent())
	{
		
		BBComponent->SetValueAsVector(FName("PointOfInterest"), Location);

	}

	switch (CurrentNPCState)
	{
	case ENPCState::Passive:
		ChangeCurrentNPCState(ENPCState::Investigate, ColorDayGameplayTags::NPC_State_Investigate);
		break;
	case ENPCState::Attack:
		break;
	case ENPCState::Investigate:
		break;
	case ENPCState::Staggered:
		break;
	case ENPCState::Dead:
		break;
	default:
		break;
	}

}

void AColorDetourCrowdAIController::OnDamagedByAnEnemy(AActor* Actor)
{
	if (UBlackboardComponent* BBComponent = GetBlackboardComponent())
	{
		if (!BBComponent->GetValueAsObject(FName("TargetActor")) && Actor)
		{
			BBComponent->SetValueAsObject(FName("TargetActor"), Actor);

		}
	}

	switch (CurrentNPCState)
	{
	case ENPCState::Passive:
		ChangeCurrentNPCState(ENPCState::Attack, ColorDayGameplayTags::NPC_State_Attack);
		break;
	case ENPCState::Attack:
		//TODO - Change place to avoide attack
		break;
	case ENPCState::Investigate:
		ChangeCurrentNPCState(ENPCState::Attack, ColorDayGameplayTags::NPC_State_Attack);
		break;
	case ENPCState::Staggered:
		break;
	case ENPCState::Dead:
		break;
	default:
		break;
	}
}

void AColorDetourCrowdAIController::ChangeCurrentNPCState(ENPCState StateToChangeTo, FGameplayTag TagToSet)
{
	auto OwningActor = GetPawn();
	
	if (!OwningActor) return;

	if (CurrentNPCState == StateToChangeTo) return;

	CurrentNPCState = StateToChangeTo;
	UColorDayFunctionLibrary::SwitchStateBasedOnGameplayTag(OwningActor, ColorDayGameplayTags::NPC_State, TagToSet);

}

void  AColorDetourCrowdAIController::ForgetAboutTarget()
{
	
	ChangeCurrentNPCState(ENPCState::Investigate, ColorDayGameplayTags::NPC_State_Investigate);

	if (UBlackboardComponent* BBComponent = GetBlackboardComponent())
	{		
		BBComponent->SetValueAsObject(FName("TargetActor"), nullptr);
		
	}

	GetWorld()->GetTimerManager().ClearTimer(ForgetPlayerTimerHandle);
}