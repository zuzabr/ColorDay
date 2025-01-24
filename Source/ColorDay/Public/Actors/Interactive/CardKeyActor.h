// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Actors/Interactive/InteractiveActor.h"
#include "CardKeyActor.generated.h"

class ADoorActor;

UCLASS()
class COLORDAY_API ACardKeyActor : public AInteractiveActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AssignedDoor")
	ADoorActor* AssignedDoor;

	UFUNCTION(BlueprintCallable, Category = "Ability|UnlockDoor")
	void UnlockAssignedDoor();
	
};
