// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "ColorInteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UColorInteractionInterface : public UInterface
{
	GENERATED_BODY()
};


class COLORDAY_API IColorInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void TryToInteractWithItem(const FGameplayTag& ColorTag) const = 0;
	virtual void TryToHitItem(const FGameplayTag& ColorTag) const = 0;
};
