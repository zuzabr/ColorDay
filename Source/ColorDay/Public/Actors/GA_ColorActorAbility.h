// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystem/Abilities/ColorDayGameplayAbility.h"
#include "GA_ColorActorAbility.generated.h"

class AColorDayActor;
class UASC_ColorActor;

UCLASS()
class COLORDAY_API UGA_ColorActorAbility : public UColorDayGameplayAbility
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	AColorDayActor* GetColorDayActor();

protected:
	UFUNCTION(BlueprintPure, Category = "ColorDayAbility|ColorActor")
	UASC_ColorActor* GetColorActorAbilitySystemComp()const;



private:
	TWeakObjectPtr<AColorDayActor> CachedColorActor;
	
};
