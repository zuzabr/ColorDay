// ZuzabrGames All rights reserved 2024


#include "ColorDayFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"

UColorDayAbilitySystemComp* UColorDayFunctionLibrary::NativeGetColorDayASC(AActor* Actor)
{
    if(!Actor)  return nullptr;
    return Cast<UColorDayAbilitySystemComp>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Actor));
}

bool UColorDayFunctionLibrary::NativeDoesActorHaveTag(AActor* Actor, FGameplayTag Tag)
{
    auto ASC = NativeGetColorDayASC(Actor);
    if (!ASC) return false;

    return (ASC->HasMatchingGameplayTag(Tag));
    
}

void UColorDayFunctionLibrary::AddGameplayTagToActor(AActor* Actor, FGameplayTag TagToAdd)
{
    auto ASC = NativeGetColorDayASC(Actor);
    if (!ASC) return;

    if (!ASC->HasMatchingGameplayTag(TagToAdd))
    {
        ASC->AddLooseGameplayTag(TagToAdd);
    }
}

void UColorDayFunctionLibrary::RemoveGameplayTagFromActor(AActor* Actor, FGameplayTag TagToRemove)
{
    auto ASC = NativeGetColorDayASC(Actor);
    if (!ASC) return;

    if (ASC->HasMatchingGameplayTag(TagToRemove))
    {
        ASC->RemoveLooseGameplayTag(TagToRemove);
    }
}

bool UColorDayFunctionLibrary::BP_DoesActorHaveTag(AActor* Actor, FGameplayTag Tag)
{
    return NativeDoesActorHaveTag(Actor, Tag);
}

float UColorDayFunctionLibrary::GetScalableFloatValueAtLevel(const FScalableFloat& ScalableFloat, float Level)
{
    return ScalableFloat.GetValueAtLevel(Level);
}

bool UColorDayFunctionLibrary::ApplyGameplayEffectSpecHandleToTargetActor(AActor* Instigator, AActor* Target, const FGameplayEffectSpecHandle& EffectSpecHandle)
{
    auto InstigatorASC = NativeGetColorDayASC(Instigator);
    auto TargetASC = NativeGetColorDayASC(Target);
    if (!InstigatorASC || !TargetASC) return false;

    FActiveGameplayEffectHandle ActiveGameplayEffectHandle = InstigatorASC->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data, TargetASC);
    return ActiveGameplayEffectHandle.WasSuccessfullyApplied();
}
 