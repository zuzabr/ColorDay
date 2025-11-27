// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Actors/ColorInteractionInterface.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "ColorCharacterBase.generated.h"

UCLASS()
class COLORDAY_API AColorCharacterBase : public ACharacter, public IColorInteractionInterface
{
	GENERATED_BODY()

public:
	AColorCharacterBase();

	virtual void TryToInteractWithItem(const FGameplayTag& ColorTag) const override;
	virtual void TryToHitItem(const FGameplayTag& ColorTag, float BaseDamage = 0.f) const override;
};
