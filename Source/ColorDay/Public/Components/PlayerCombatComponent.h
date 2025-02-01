// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Components/CombatComponent.h"
#include "ColorDayCoreTypes.h"
#include "GameplayTagContainer.h"
#include "PlayerCombatComponent.generated.h"

class AColorDayGun;
class AColorDayActor;

UCLASS()
class COLORDAY_API UPlayerCombatComponent : public UCombatComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void RegisterWeapon(FGameplayTag WeaponTag, AColorDayGun* Weapon, bool bEquipped = false);

	UFUNCTION(BlueprintCallable, Category = "Combat")
	AColorDayGun* GetCarriedWeaponByTag(FGameplayTag WeaponTag) const;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	AColorDayGun* GetEquippedWeapon() const;

	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	FGameplayTag EquippedWeaponTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat|Carring item ability")
	FItemInputData CarringItemData;

private:
	TMap<FGameplayTag, AColorDayGun*> CarriedWeaponMap;

	
};
