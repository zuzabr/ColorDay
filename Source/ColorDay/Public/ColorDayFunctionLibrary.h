// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "ColorDayFunctionLibrary.generated.h"

class UColorDayAbilitySystemComp;
struct FScalableFloat;

UCLASS()
class COLORDAY_API UColorDayFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UColorDayAbilitySystemComp* NativeGetColorDayASC(AActor* Actor);
	static bool NativeDoesActorHaveTag(AActor* Actor, FGameplayTag Tag);

	UFUNCTION(BlueprintCallable, Category = "ColorDay|FunctionLibrary")
	static void AddGameplayTagToActor(AActor* Actor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "ColorDay|FunctionLibrary")
	static void RemoveGameplayTagFromActor(AActor* Actor, FGameplayTag TagToRemove);

	UFUNCTION(BlueprintCallable, Category = "ColorDay|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag"))
	static bool BP_DoesActorHaveTag(AActor* Actor, FGameplayTag Tag);

	UFUNCTION(BlueprintPure, Category = "ColorDay|FunctionLibrary", meta = (CompactNodeTitle = "Get Value At Level"))
	static float GetScalableFloatValueAtLevel(const FScalableFloat& ScalableFloat, float Level = 1.f);

	UFUNCTION(BlueprintCallable, Category = "ColorDay|FunctionLibrary")
	static bool ApplyGameplayEffectSpecHandleToTargetActor(AActor* Instigator, AActor* Target, const FGameplayEffectSpecHandle& EffectSpecHandle);

	UFUNCTION(BlueprintCallable, Category = "ColorDay|FunctionLibrary")
	static void SwitchStateBasedOnGameplayTag(AActor* Actor, FGameplayTag State, FGameplayTag TagToSet);
};
