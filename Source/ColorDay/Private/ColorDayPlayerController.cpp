// ZuzabrGames All rights reserved 2024


#include "ColorDayPlayerController.h"

AColorDayPlayerController::AColorDayPlayerController()
{
	PlayerTeamID = FGenericTeamId(0);
}

FGenericTeamId AColorDayPlayerController::GetGenericTeamId() const
{
	return PlayerTeamID;
}
