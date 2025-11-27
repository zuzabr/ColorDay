// ZuzabrGames All rights reserved 2024


#include "Components/PlayerCombatComponent.h"
#include "Actors/ColorDayActor.h"
#include "ColorDay/ColorDayCharacter.h"
#include "Actors/Weapon/ColorDayGun.h"

void UPlayerCombatComponent::RegisterWeapon(FGameplayTag WeaponTag, AColorDayGun* Weapon, bool bEquipped)
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

AColorDayGun* UPlayerCombatComponent::GetCarriedWeaponByTag(FGameplayTag WeaponTag) const
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

AColorDayGun* UPlayerCombatComponent::GetEquippedWeapon() const
{
	if (!EquippedWeaponTag.IsValid()) return nullptr;

	return GetCarriedWeaponByTag(EquippedWeaponTag);
}
