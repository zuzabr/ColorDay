// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/ColorDayAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "ColorDayFunctionLibrary.h"
#include "ColorDayDebugHelper.h"
#include "ColorDayGameplayTags.h"

UColorDayAttributeSet::UColorDayAttributeSet()
{
	InitCurrentHealth(100.f);
	InitMaxHealth(100.f);
	InitCurrentEnergy(100.f);
	InitMaxEnergy(100.f);
	InitAttackPower(100.f);
	InitShieldPower(100.f);
}

void UColorDayAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);
	}

	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDone, 0.f, GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);

		const FString DebugString = FString::Printf(TEXT("Old Health: %f, Damage Done: %f, New Current Health: %f"), OldHealth, DamageDone, NewCurrentHealth);
		Debug::Print(DebugString, FColor::Green);


		// Manage Character Death
		if (NewCurrentHealth == 0.f)
		{
			UColorDayFunctionLibrary::AddGameplayTagToActor(Data.Target.GetAvatarActor(), ColorDayGameplayTags::Character_Status_Dead);
		}
	}


}
