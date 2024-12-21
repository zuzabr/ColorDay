// Copyright Epic Games, Inc. All Rights Reserved.


#include "ColorDayWeaponComponent.h"
#include "ColorDayCharacter.h"
#include "ColorDayProjectile.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Animation/AnimInstance.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"



void UColorDayWeaponComponent::SwitchAmmoType()
{
	if (AmmoTypes.Num() == 0) return;
		
	CurrentAmmoIndex = (CurrentAmmoIndex + 1) % AmmoTypes.Num();
	
}

// Sets default values for this component's properties
UColorDayWeaponComponent::UColorDayWeaponComponent()
{
	// Default offset from the character location for projectiles to spawn
	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);
}


void UColorDayWeaponComponent::Fire()
{
	if (!Character|| Character->GetController() == nullptr) return;
	
	const FAmmoType& CurrentAmmo = AmmoTypes[CurrentAmmoIndex];
	const auto CurAmmoClass = CurrentAmmo.ProjectileClass;
	
	// Try and fire a projectile
	if (!CurAmmoClass||!GetWorld()) return;
	UWorld* const World = GetWorld();
		
	if (!World) return;
		
	APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
	const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
	// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
	const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);
	
	//Set Spawn Collision Handling Override
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	
	// Spawn the projectile at the muzzle
	World->SpawnActor<AColorDayProjectile>(CurAmmoClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
		
	// Try and play the sound if specified
	const auto CurFireSound = CurrentAmmo.FireSound;	
	if (CurFireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, CurFireSound, Character->GetActorLocation());
	}
	
	// Try and play a firing animation if specified
	const auto CurFireAnim = CurrentAmmo.FireAnimation;
	if (CurFireAnim != nullptr)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Character->GetMesh1P()->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(CurFireAnim, 1.f);
		}
	}
}

bool UColorDayWeaponComponent::AttachWeapon(AColorDayCharacter* TargetCharacter)
{
	Character = TargetCharacter;

	// Check that the character is valid, and has no weapon component yet
	if (Character == nullptr || Character->GetInstanceComponents().FindItemByClass<UColorDayWeaponComponent>())
	{
		return false;
	}

	// Attach the weapon to the First Person Character
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	AttachToComponent(Character->GetMesh1P(), AttachmentRules, FName(TEXT("GripPoint")));

	// Set up action bindings
	if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			// Set the priority of the mapping to 1, so that it overrides the Jump action with the Fire action when using touch input
			Subsystem->AddMappingContext(FireMappingContext, 1);
		}

		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
		{
			// Fire
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &UColorDayWeaponComponent::Fire);
			EnhancedInputComponent->BindAction(SwitchAmmoAction, ETriggerEvent::Triggered, this, &UColorDayWeaponComponent::SwitchAmmoType);
		}
	}

	return true;
}

void UColorDayWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// ensure we have a character owner
	if (Character != nullptr)
	{
		// remove the input mapping context from the Player Controller
		if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->RemoveMappingContext(FireMappingContext);
			}
		}
	}

	// maintain the EndPlay call chain
	Super::EndPlay(EndPlayReason);
}