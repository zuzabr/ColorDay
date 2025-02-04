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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FWeaponData PlayerWeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray< FGameplayAbilitySpecHandle>& SpecHandles);

	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire(FGameplayEffectSpecHandle ProjectileDamageEffectSpecHandle);


	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SwitchAmmoType();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AmmoInfo)
	TArray<FAmmoType> AmmoTypes;


	UFUNCTION(BlueprintPure, Category = "Weapon")
	FAmmoType GetCurrentAmmoType();

private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;

	/*Iterator for ammo*/
	int32 CurrentAmmoIndex = 0;
	int32 CurrentAmmoNumber;
	AColorDayCharacter* Character;


	
};
