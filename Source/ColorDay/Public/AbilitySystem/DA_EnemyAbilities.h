// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/DA_StartupHeroAbilities.h"
#include "DA_EnemyAbilities.generated.h"

class UGA_ColorDayEnemy;

UCLASS()
class COLORDAY_API UDA_EnemyAbilities : public UDA_StartupHeroAbilities
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UColorDayAbilitySystemComp* InASC, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "EnemyAbilities")
	TArray< TSubclassOf <UGA_ColorDayEnemy > > EnemyAbilities;
	
};
