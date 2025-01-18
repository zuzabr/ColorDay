// ZuzabrGames All rights reserved 2024


#include "Components/CombatComponent.h"
#include "ColorDayDebugHelper.h"

// Sets default values for this component's properties
UCombatComponent::UCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UCombatComponent::RegisterWeapon(FGameplayTag WeaponTag, AColorDayGun* Weapon, bool bEquipped)
{
	if (!CarriedWeaponMap.Contains(WeaponTag) && Weapon)
	{
		CarriedWeaponMap.Emplace(WeaponTag, Weapon);
		

		if (bEquipped)
		{
			EquippedWeaponTag = WeaponTag;
		}
	}

	
}

AColorDayGun* UCombatComponent::GetCarriedWeaponByTag(FGameplayTag WeaponTag) const
{
	if (CarriedWeaponMap.Contains(WeaponTag))
	{
		if (AColorDayGun* const* FoundWeapon = CarriedWeaponMap.Find(WeaponTag))
		{
			return *FoundWeapon;
		}
	}

	return nullptr;
}

AColorDayGun* UCombatComponent::GetEquippedWeapon() const
{
	if (!EquippedWeaponTag.IsValid()) return nullptr;

	return GetCarriedWeaponByTag(EquippedWeaponTag);
}


// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	
	
}




