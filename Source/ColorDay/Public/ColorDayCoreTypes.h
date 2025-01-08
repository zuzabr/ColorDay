// ZuzabrGames All rights reserved 2024

#pragma once

#include "GameplayTagContainer.h"
#include "ColorDayCoreTypes.generated.h"

class AColorDayProjectile;
class UNiagaraSystem;
class AColorDayActor;
class UPlayerLinkedAnimLayer;
class UColorDayGameplayAbility;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FAmmoType
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AmmoName;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AColorDayProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* FireAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOpened = true;



};

USTRUCT(BlueprintType)
struct FProjectileInfo
{
	GENERATED_USTRUCT_BODY()

	// Niagara System for paint splatter
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* PaintSplatterEffect;

	// Material for paint decal
	UPROPERTY(EditAnywhere)
	UMaterialInterface* PaintDecalMaterial;

	// Size of the decal
	UPROPERTY(EditAnywhere)
	FVector DecalSize = FVector(40.f, 40.f, 40.f);

	UPROPERTY(EditAnywhere)
	TSubclassOf<AColorDayActor> ActorToSpawn;

};

USTRUCT(BlueprintType)
struct FPlayerAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UColorDayGameplayAbility> AbilityToGrant;

	bool IsValid() const;

};

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UPlayerLinkedAnimLayer> WeaponAnimLayerToLink;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty ="InputTag"))
	TArray<FPlayerAbilitySet> DefaultWeaponAbilities;
};

