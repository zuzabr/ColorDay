// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/ColorDayGameplayAbility.h"
#include "GA_ColorDayEnemy.generated.h"

class ANPCCharacter;
class UEnemyCombatComponent;

UCLASS()
class COLORDAY_API UGA_ColorDayEnemy : public UColorDayGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	ANPCCharacter* GetNPC();


	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	UEnemyCombatComponent* GetCombatComponent() const;

	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	FGameplayEffectSpecHandle MakeEnemyDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, const FScalableFloat& ScalableDamage, FGameplayTag ColorTag);

private:
	TWeakObjectPtr<ANPCCharacter> CachedNPC;
	
};
