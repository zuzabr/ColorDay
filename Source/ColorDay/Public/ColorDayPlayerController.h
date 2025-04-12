// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "ColorDayPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class COLORDAY_API AColorDayPlayerController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	AColorDayPlayerController();

	virtual FGenericTeamId GetGenericTeamId() const override;

private:
	FGenericTeamId PlayerTeamID;
	
};
