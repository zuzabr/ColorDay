// ZuzabrGames All rights reserved 2024

#pragma once


#include "ColorDayCoreTypes.generated.h"

class AColorDayProjectile;
class UNiagaraSystem;
class AColorActor;

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
	TSubclassOf<AColorActor> ActorToSpawn;

};