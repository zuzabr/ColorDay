// Copyright Epic Games, Inc. All Rights Reserved.

#include "ColorDayCharacter.h"
#include "ColorDayProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/ColorDayInputComponent.h"

#include "ColorDayPlayerController.h"

#include "ColorDayGameplayTags.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"
#include "AbilitySystem/ColorDayAttributeSet.h"
#include "AbilitySystem/DA_StartupHeroAbilities.h"
#include "Actors/ColorInteractionInterface.h"

#include "Components/CombatComponent.h"

#include "ColorDayDebugHelper.h"
#include "DrawDebugHelpers.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AColorDayCharacter

AColorDayCharacter::AColorDayCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = true;
	Mesh1P->CastShadow = true;
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	// Create Ability System
	ColorDayAbilitySystemComp = CreateDefaultSubobject<UColorDayAbilitySystemComp>(TEXT("ColorDayAbilitySystemComp"));
	ColorDayAttributeSet = CreateDefaultSubobject<UColorDayAttributeSet>(TEXT("ColorDayAttributeSet"));

	// Create Combat Component
	CombatComponent = CreateDefaultSubobject< UCombatComponent>(TEXT("CombatComponent"));

	InteractionTag = ColorDayGameplayTags::ColorActor_Instigator_Player;

	SetDefaulSpeed();

}



//////////////////////////////////////////////////////////////////////////// Input

void AColorDayCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (AColorDayPlayerController* PlayerController = Cast<AColorDayPlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			checkf(InputConfigDataAsset, TEXT("Input config isn't assigned"));
			Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
		}
	}
}

void AColorDayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	UColorDayInputComponent* ColorDayInputComponent = CastChecked<UColorDayInputComponent>(PlayerInputComponent);
	checkf(InputConfigDataAsset, TEXT("Input config isn't assigned"));

	// Move and Look
	ColorDayInputComponent->BindNativeInputAction(InputConfigDataAsset, ColorDayGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &AColorDayCharacter::Move);
	ColorDayInputComponent->BindNativeInputAction(InputConfigDataAsset, ColorDayGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &AColorDayCharacter::Look);

	// Jumping
	ColorDayInputComponent->BindNativeInputAction(InputConfigDataAsset, ColorDayGameplayTags::InputTag_Jump, ETriggerEvent::Started, this, &ACharacter::Jump);
	ColorDayInputComponent->BindNativeInputAction(InputConfigDataAsset, ColorDayGameplayTags::InputTag_Jump, ETriggerEvent::Completed, this, & ACharacter::StopJumping);
	
	// Crouching
	ColorDayInputComponent->BindNativeInputAction(InputConfigDataAsset, ColorDayGameplayTags::InputTag_Crouch, ETriggerEvent::Started, this, &AColorDayCharacter::CrouchToggle);
	
	// Sprinting
	ColorDayInputComponent->BindNativeInputAction(InputConfigDataAsset, ColorDayGameplayTags::InputTag_Sprint, ETriggerEvent::Started, this, &AColorDayCharacter::Sprint);
	ColorDayInputComponent->BindNativeInputAction(InputConfigDataAsset, ColorDayGameplayTags::InputTag_Sprint, ETriggerEvent::Completed, this, &AColorDayCharacter::StopSprint);

	// Interacting
	ColorDayInputComponent->BindNativeInputAction(InputConfigDataAsset, ColorDayGameplayTags::InputTag_Interact, ETriggerEvent::Triggered, this, &AColorDayCharacter::Interact);

	// Bind Weapon Input Mapping
	ColorDayInputComponent->BindWeaponInputAction(InputConfigDataAsset, this, &AColorDayCharacter::AbilityInputPressed, &AColorDayCharacter::AbilityInputReleased);
			
}

void AColorDayCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (ColorDayAbilitySystemComp)
	{
		ColorDayAbilitySystemComp->InitAbilityActorInfo(this, this);
	}

	//ensure(!StartupAbilities.IsNull());

	if (!StartupAbilities.IsNull())
	{
		if (auto* LoadedData = StartupAbilities.LoadSynchronous()) 
		{
			LoadedData->GiveToAbilitySystemComponent(ColorDayAbilitySystemComp);
		}
	}
}

bool AColorDayCharacter::CanSprint()
{
	if (bCanSprint && !bIsCrouched) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AColorDayCharacter::SetDefaulSpeed()
{
	if (!GetCharacterMovement()) return;
	GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed;
	
}

UAbilitySystemComponent* AColorDayCharacter::GetAbilitySystemComponent() const
{
	return GetColorDayAbilitySystemComp();
}

void AColorDayCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AColorDayCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AColorDayCharacter::CrouchToggle(const FInputActionValue& Value)
{
	if (!bIsCrouched)
	{
		UE_LOG(LogTemplateCharacter, Warning, TEXT("Crouching"));
		StopSprint(Value);
		Crouch();
	}
	else
	{
		UnCrouch();
	}
	
}

void AColorDayCharacter::Sprint(const FInputActionValue& Value)
{
	if (CanSprint() && GetCharacterMovement())
	{
		UE_LOG(LogTemplateCharacter, Warning, TEXT("Sprinting"));
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
}

void AColorDayCharacter::StopSprint(const FInputActionValue& Value)
{
	SetDefaulSpeed();
}

void AColorDayCharacter::Interact(const FInputActionValue& Value)
{
	FVector Start;
	FRotator ViewRotation;
	GetActorEyesViewPoint(Start, ViewRotation);

	FVector End = Start + (ViewRotation.Vector() * InteractionRange);

	FHitResult HitResult;
	FCollisionQueryParams TraceParams;
	TraceParams.bTraceComplex = true;
	TraceParams.AddIgnoredActor(this); // Ignore the player character

	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 2.0f);
	// Perform line trace
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility, TraceParams))
	{
		// Check if the actor has a specific tag or interface
		AActor* HitActor = HitResult.GetActor();
		if (!HitActor) return;
		
		if (auto InteractionInterface = Cast<IColorInteractionInterface>(HitActor))
		{
			InteractionInterface->TryToInteractWithItem(InteractionTag);
		}
	}

	// Debug visualization
	
}

void AColorDayCharacter::AbilityInputPressed(FGameplayTag IputTag)
{
	ColorDayAbilitySystemComp->OnAbilityInputPressed(IputTag);
}

void AColorDayCharacter::AbilityInputReleased(FGameplayTag IputTag)
{
	ColorDayAbilitySystemComp->OnAbilityInputReleased(IputTag);
}
