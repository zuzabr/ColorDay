// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GA_ColorActorAbility.generated.h"

class AColorDayActor;
class UASC_ColorActor;

UCLASS()
class COLORDAY_API UGA_ColorActorAbility : public UGameplayAbility
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	AColorDayActor* GetColorDayActor();

protected:
	UFUNCTION(BlueprintPure, Category = "ColorDayAbility")
	UASC_ColorActor* GetColorColorDayAbilitySystemComp()const;

private:
	TWeakObjectPtr<AColorDayActor> CachedColorActor;
	
};
