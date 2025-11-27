// ZuzabrGames All rights reserved 2024


#include "NPC/NPCCharacter.h"
#include "ColorDayGameplayTags.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"
#include "AbilitySystem/ColorDayAttributeSet.h"
#include "AbilitySystem/DA_EnemyAbilities.h"
#include "Components/EnemyCombatComponent.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/AssetManager.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Actors/PatrolSplineActor.h"
#include "ColorDayDebugHelper.h"

// Sets default values
ANPCCharacter::ANPCCharacter()
{
 	
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 180.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;
	GetCharacterMovement()->MaxFlySpeed = 5000.f;

	ColorDayAbilitySystemComp = CreateDefaultSubobject<UColorDayAbilitySystemComp>(TEXT("ColorDayAbilitySystemComp"));
	ColorDayAttributeSet = CreateDefaultSubobject<UColorDayAttributeSet>(TEXT("ColorDayAttributeSet"));

	// Create Combat Component
	CombatComponent = CreateDefaultSubobject< UEnemyCombatComponent>(TEXT("CombatComponent"));

	InteractionTag = ColorDayGameplayTags::ColorActor_Instigator_NPC;

}

UAbilitySystemComponent* ANPCCharacter::GetAbilitySystemComponent() const
{
	return GetColorDayAbilitySystemComp();
}

void ANPCCharacter::Teleport(UParticleSystem* TeleportFX)
{
	auto const MovementComp = GetCharacterMovement();
	if (!MovementComp) return;

	MovementComp->SetMovementMode(EMovementMode::MOVE_Flying);
	MovementComp->MaxAcceleration = 99999.f;

	if (GetMesh())
	{
		GetMesh()->SetVisibility(false, true);		
	}

	if (GetCapsuleComponent())
	{
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	}
	if (TeleportFX)
	{
		TeleportEmitter = UGameplayStatics::SpawnEmitterAttached(TeleportFX, GetMesh(), "spine_01");		
	}
	
	
}

void ANPCCharacter::TeleportEnd()
{
	auto const MovementComp = GetCharacterMovement();
	if (!MovementComp) return;

	MovementComp->SetMovementMode(EMovementMode::MOVE_Walking);
	MovementComp->MaxAcceleration = 1500.f;

	if (GetMesh())
	{
		GetMesh()->SetVisibility(true, true);
		
	}

	if (GetCapsuleComponent())
	{
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	}

	if (TeleportEmitter)
	{
		TeleportEmitter->DestroyComponent(true);
	}
	
}

void ANPCCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitEnemyAbilities();
}

void ANPCCharacter::TryToInteractWithItem(const FGameplayTag& ColorTag) const
{
	Debug::Print(TEXT("Character was tried to Interact"));
}

void ANPCCharacter::TryToHitItem(const FGameplayTag& ColorTag, float BaseDamage) const
{
	FGameplayEventData Data;
	//UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetAbilitySystemComponent()->GetAvatarActor(), ColorTag, Data);
}


void ANPCCharacter::InitEnemyAbilities()
{
	if (EnemyAbilities.IsNull()) return;
	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		EnemyAbilities.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this]()
			{
				if (auto Ability = EnemyAbilities.Get())
				{
					Ability->GiveToAbilitySystemComponent(ColorDayAbilitySystemComp);
				}
			}
		)
	);
}

