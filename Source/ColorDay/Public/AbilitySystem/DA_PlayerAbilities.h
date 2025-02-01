// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/DA_StartupHeroAbilities.h"
#include "ColorDayCoreTypes.h"
#include "DA_PlayerAbilities.generated.h"

/**
 * 
 */
UCLASS()
class COLORDAY_API UDA_PlayerAbilities : public UDA_StartupHeroAbilities
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UColorDayAbilitySystemComp* InASC, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Start Abilities")
	TArray<FPlayerAbilitySet> PlayerStartAbilitySets;
	
};
