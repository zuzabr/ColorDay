// ZuzabrGames All rights reserved 2024


#include "Actors/ColorDayActor.h"
#include "Actors/GA_ColorActorAbility.h"
#include "Actors/ASC_ColorActor.h"
#include "AbilitySystem/ColorDayAttributeSet.h"
#include "ColorDayGameplayTags.h"


#include "ColorDayDebugHelper.h"

// Sets default values
AColorDayActor::AColorDayActor()
{

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
			
	ASC_ColorActor = CreateDefaultSubobject<UASC_ColorActor>(TEXT("ColorActorAbilitySystemComp"));
	ColorDayAttributeSet = CreateDefaultSubobject<UColorDayAttributeSet>(TEXT("ColorDayAttributeSet"));
	
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetSimulatePhysics(HasPhysics);
	}

}


UAbilitySystemComponent* AColorDayActor::GetAbilitySystemComponent() const
{
	return GetColorDayAbilitySystemComp();
}

void AColorDayActor::GrantAbilities(int32 ApplyLevel)
{
	for (const FColorActorAbilitySet& AbilitySet : ColorActorAbilitySet)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = ASC_ColorActor->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.ColorTag);

		ASC_ColorActor->GiveAbility(AbilitySpec);

	}
	if (ActiveFromStart)
	{
		ASC_ColorActor->AddLooseGameplayTag(ColorDayGameplayTags::ColorActor_Status_Active, 1);
	}
	
	
	if (HasPhysics) 
	{
		ASC_ColorActor->AddLooseGameplayTag(ColorDayGameplayTags::ColorActor_Status_HasPhysics, 1);
	}
		
}

// Called when the game starts or when spawned
void AColorDayActor::BeginPlay()
{
	Super::BeginPlay();

	ASC_ColorActor->InitAbilityActorInfo(this, this);
	GrantAbilities();
	//ASC_ColorActor->HasMatchingGameplayTag(ActorHasPhysics.GetTagName())
	
}

void AColorDayActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	DynamicMaterial = StaticMeshComponent->CreateDynamicMaterialInstance(0, StaticMeshComponent->GetMaterial(0));
	
}



void AColorDayActor::TryToInteractWithItem(const FGameplayTag& ColorTag) const
{
	Debug::Print(TEXT("Actor was tried to Interact"));
	
}

void AColorDayActor::TryToHitItem(const FGameplayTag& ColorTag) const
{
	Debug::Print(TEXT("Actor was tried to hit"));	
}



