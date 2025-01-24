// ZuzabrGames All rights reserved 2024


#include "Components/CombatComponent.h"
#include "Actors/ColorDayActor.h"
#include "ColorDay/ColorDayCharacter.h"
#include "Animation/PlayerLinkedAnimLayer.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"
#include "EnhancedInputSubsystems.h"
#include "ColorDayPlayerController.h"
#include "Engine/LocalPlayer.h"



// Sets default values for this component's properties
UCombatComponent::UCombatComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

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



void UCombatComponent::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& SpecHandles)
{
	GrantedAbilitySpecHandles = SpecHandles;
}

TArray<FGameplayAbilitySpecHandle> UCombatComponent::GetGrantedAbilitySpecHandles() const
{
	return GrantedAbilitySpecHandles;
}


// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
		
}




