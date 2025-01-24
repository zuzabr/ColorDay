// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Actors/Interactive/InteractiveActor.h"
#include "DoorActor.generated.h"

/**
 * 
 */
UCLASS()
class COLORDAY_API ADoorActor : public AInteractiveActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ColorAbilitySystem|Abilities")
	bool bInitiallyLocked = true;
	
};
