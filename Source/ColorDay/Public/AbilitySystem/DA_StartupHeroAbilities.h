// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ColorDayCoreTypes.h"
#include "DA_StartupHeroAbilities.generated.h"

class UColorDayGameplayAbility;
class UColorDayAbilitySystemComp;
class UGameplayEffect;


UCLASS()
class COLORDAY_API UDA_StartupHeroAbilities : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UColorDayAbilitySystemComp* InASC, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly,Category = "StartUpData")
	TArray<TSubclassOf<UColorDayGameplayAbility>> ActivateOnGivenAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UColorDayGameplayAbility>> ReactiveAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UGameplayEffect>> StartUpGameplayEffects;

	void GrantAbilities(const TArray<TSubclassOf<UColorDayGameplayAbility>>& AbilitiesToGive, UColorDayAbilitySystemComp* InASC, int32 ApplyLevel = 1);


};
