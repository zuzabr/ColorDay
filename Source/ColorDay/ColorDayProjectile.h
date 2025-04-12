// Copyright Zuzabr Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColorDayCoreTypes.h"
#include "GameplayEffectTypes.h"
#include "ColorDayProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

UCLASS(config=Game)
class AColorDayProjectile : public AActor
{
	GENERATED_BODY()

protected:
	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = ProjectileInfo)
	FProjectileInfo ProjectileInfo;
	

public:
	AColorDayProjectile();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

	FGameplayTag GetProjectileGameplayTag();



	UPROPERTY(BlueprintReadOnly, Category = ProjectileInfo, meta = (ExposeOnSpawn = "true"))
	FGameplayEffectSpecHandle ProjectileDamageEffectSpecHandle;

	void SpawnColorActor(const FHitResult& Hit);

private:
	void HandleApplyProjectileDamage(AActor* HitActor);
};

