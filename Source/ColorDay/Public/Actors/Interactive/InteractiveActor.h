// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Actors/ColorDayActor.h"
#include "InteractiveActor.generated.h"

/**
 * 
 */
UCLASS()
class COLORDAY_API AInteractiveActor : public AColorDayActor
{
	GENERATED_BODY()

public:
	virtual void TryToHitItem(const FGameplayTag& ColorTag) const override;
	virtual void TryToInteractWithItem(const FGameplayTag& ColorTag) const override;
	
};
