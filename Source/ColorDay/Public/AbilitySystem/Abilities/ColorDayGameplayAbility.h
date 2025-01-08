// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ColorDayGameplayAbility.generated.h"

class UCombatComponent;
class UColorDayAbilitySystemComp;
class AColorDayCharacter;
class AColorDayPlayerController;

UENUM(BlueprintType)
enum class EColorDayAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

UCLASS()
class COLORDAY_API UColorDayGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	AColorDayCharacter* GetColorDayCharacter();

	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	AColorDayPlayerController* GetColorController();
	
protected:

	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)override;

	UPROPERTY(EditDefaultsOnly, Category = "ColorDayAbility")
	EColorDayAbilityActivationPolicy AbilityActivationPolicy = EColorDayAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	UCombatComponent* GetCombatComponent() const;

	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	UColorDayAbilitySystemComp* GetColorColorDayAbilitySystemComp()const;

private:
	TWeakObjectPtr<AColorDayCharacter> CachedCharacter;
	TWeakObjectPtr<AColorDayPlayerController> CachedController;
};
