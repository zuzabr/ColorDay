// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ColorDayCoreTypes.h"
#include "ColorDayAbilitySystemComp.generated.h"

/**
 * 
 */
UCLASS()
class COLORDAY_API UColorDayAbilitySystemComp : public UAbilitySystemComponent
{
	GENERATED_BODY()
	

public:
	void OnAbilityInputPressed(const FGameplayTag& InputTag);
	void OnAbilityInputReleased(const FGameplayTag& InputTag);

	UFUNCTION(BlueprintCallable, Category = "ColorDay|Ability", meta = (ApplyLevel = "1"))
	void GrantAdditionalAbilities(const TArray< FPlayerAbilitySet>& Abilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& GrantedAbilitySpecHandles);

	UFUNCTION(BlueprintCallable, Category = "ColorDay|Ability")
	void RemovePlayerWeaponAbilities(UPARAM(ref)TArray<FGameplayAbilitySpecHandle>& AbilitySpecHandlesToRemove);

	UFUNCTION(BlueprintCallable, Category = "ColorDay|Ability")
	bool TryActivateAbilityByTag(FGameplayTag AbilityTagToActivate);

};
