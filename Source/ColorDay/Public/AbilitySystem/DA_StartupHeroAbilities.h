// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_StartupHeroAbilities.generated.h"

class UColorDayGameplayAbility;
class UColorDayAbilitySystemComp;

UCLASS()
class COLORDAY_API UDA_StartupHeroAbilities : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UColorDayAbilitySystemComp* InASC, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly,Category = "Abilities")
	TArray<TSubclassOf<UColorDayGameplayAbility>> ActivateOnGivenAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<UColorDayGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UColorDayGameplayAbility>>& AbilitiesToGive, UColorDayAbilitySystemComp* InASC, int32 ApplyLevel = 1);
};
