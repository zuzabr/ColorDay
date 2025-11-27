// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Actors/ColorDayActor.h"
#include "ColorDayCoreTypes.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameplayEffectTypes.h"
#include "ColorDayGun.generated.h"

class AColorDayCharacter;


UCLASS()
class COLORDAY_API AColorDayGun : public AColorDayActor
{
	GENERATED_BODY()

public:
	AColorDayGun();

// Ability System
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponInformation")
	FWeaponData PlayerWeaponData; 

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray< FGameplayAbilitySpecHandle>& SpecHandles);

	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;

	UFUNCTION(BlueprintCallable, Category = "WeaponInformation")
	void Fire(FGameplayEffectSpecHandle ProjectileDamageEffectSpecHandle);

	UFUNCTION(BlueprintCallable, Category = "WeaponInformation")
	void SwitchAmmoType();
// Ability System

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;

protected:
	virtual void BeginPlay() override;

	
	UFUNCTION(BlueprintPure, Category = "Weapon")
	FGameplayTag GetCurrentAmmoColorTag();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoInfo)
	TArray<FAmmoType> AmmoTypes;

	UFUNCTION(BlueprintPure, Category = "Weapon")
	FAmmoType GetCurrentAmmoType();
	


private:

	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;

	/*Iterator for  projectile ammo*/
	int32 CurrentAmmoIndex = 0;

	AColorDayCharacter* Character;

	
};
