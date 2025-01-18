// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ColorDayCoreTypes.h"
#include "ASC_ColorActor.generated.h"

/**
 * 
 */
UCLASS()
class COLORDAY_API UASC_ColorActor : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void ActivateAbility(const FGameplayTag& ColorTag);
	
	/*UFUNCTION(BlueprintCallable, Category = "ColorDay|Ability", meta = (ApplyLevel = "1"))
	void GrantPlayerWeaponAbilities(const TArray< FPlayerAbilitySet>& Abilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& GrantedAbilitySpecHandles);

	UFUNCTION(BlueprintCallable, Category = "ColorDay|Ability")
	void RemovePlayerWeaponAbilities(UPARAM(ref)TArray<FGameplayAbilitySpecHandle>& AbilitySpecHandlesToRemove);*/
	
};
