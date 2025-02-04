// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/ColorDayGameplayAbility.h"
#include "GA_ColorDayPlayer.generated.h"

class AColorDayCharacter;
class AColorDayPlayerController;
class UPlayerCombatComponent;

UCLASS()
class COLORDAY_API UGA_ColorDayPlayer : public UColorDayGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	AColorDayCharacter* GetColorDayCharacter();

	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	AColorDayPlayerController* GetColorController();

	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	UPlayerCombatComponent* GetCombatComponent() const;

	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	FGameplayEffectSpecHandle MakePlayerDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, const FScalableFloat& InDamageScalableFloat);

private:
	TWeakObjectPtr<AColorDayCharacter> CachedCharacter;
	TWeakObjectPtr<AColorDayPlayerController> CachedController;
};
