// ZuzabrGames All rights reserved 2024


#include "MultiplayerSessionsSubsystem.h"
#include "ColorDayDebugHelper.h"



UMultiplayerSessionsSubsystem::UMultiplayerSessionsSubsystem()
{
	Debug::Print("SessionsSubsystem Constructor", FColor::Yellow);
}

void UMultiplayerSessionsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Debug::Print("SessionsSubsystem Initialized", FColor::Yellow);
}

void UMultiplayerSessionsSubsystem::Deinitialize()
{
	UE_LOG(LogTemp, Warning, TEXT("GameSession Deinitialized"));
}
