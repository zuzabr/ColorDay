// ZuzabrGames All rights reserved 2024


#include "Actors/Weapon/ColorDayGun.h"
#include "ColorDay/ColorDayCharacter.h"
#include "ColorDay/ColorDayProjectile.h"
#include "ColorDayPlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimInstance.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"

AColorDayGun::AColorDayGun()
{
	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);
	
}

void AColorDayGun::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<AColorDayCharacter>(GetOwner());
}

FAmmoType AColorDayGun::GetCurrentAmmoType()
{
	auto AmmoType = AmmoTypes[CurrentAmmoIndex];
	auto Projectile = AmmoType.ProjectileClass.GetDefaultObject();

	if (Projectile)
	{
		Projectile->GetProjectileGameplayTag();
	}

	return AmmoTypes[CurrentAmmoIndex];
}

FGameplayTag AColorDayGun::GetCurrentAmmoColorTag()
{
	auto AmmoType = AmmoTypes[CurrentAmmoIndex];
	auto Projectile = AmmoType.ProjectileClass.GetDefaultObject();

	if (Projectile)
	{
		return Projectile->GetProjectileGameplayTag();
	}
	
	return FGameplayTag();
}

void AColorDayGun::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& SpecHandles)
{
	GrantedAbilitySpecHandles = SpecHandles;
}

TArray<FGameplayAbilitySpecHandle> AColorDayGun::GetGrantedAbilitySpecHandles() const
{
	return GrantedAbilitySpecHandles;
}

void AColorDayGun::Fire(FGameplayEffectSpecHandle ProjectileDamageEffectSpecHandle)
{
	if (!Character || Character->GetController() == nullptr) return;

	const FAmmoType& CurrentAmmo = AmmoTypes[CurrentAmmoIndex];
	const auto CurAmmoClass = CurrentAmmo.ProjectileClass;

	// Try and fire a projectile
	if (!CurAmmoClass || !GetWorld()) return;
	UWorld* const World = GetWorld();


	//************************************Spawn Projectile*************************************************
	AColorDayPlayerController* PlayerController = Cast<AColorDayPlayerController>(Character->GetController());
	const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
	// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
	const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);

	//Set Spawn Collision Handling Override
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	// Spawn the projectile at the muzzle
	auto SpawnedProjectile = World->SpawnActor<AColorDayProjectile>(CurAmmoClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
	if(SpawnedProjectile) 
	{ 
		SpawnedProjectile->SetOwner(GetOwner());
		SpawnedProjectile->ProjectileDamageEffectSpecHandle = ProjectileDamageEffectSpecHandle;
	}
	

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



void AColorDayGun::SwitchAmmoType()
{
	if (AmmoTypes.IsEmpty()) return;

	CurrentAmmoIndex = (CurrentAmmoIndex + 1) % AmmoTypes.Num();

}


