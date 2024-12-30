// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ColorDayGameplayAbility.generated.h"

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
	
protected:

	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)override;

	UPROPERTY(EditDefaultsOnly, Category = "ColorDayAbility")
	EColorDayAbilityActivationPolicy AbilityActivationPolicy = EColorDayAbilityActivationPolicy::OnTriggered;

};
