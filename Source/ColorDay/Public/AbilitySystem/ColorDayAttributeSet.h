// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/ColorDayAbilitySystemComp.h"
#include "ColorDayAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class COLORDAY_API UColorDayAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UColorDayAttributeSet();

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UColorDayAttributeSet, CurrentHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UColorDayAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Energy")
	FGameplayAttributeData CurrentEnergy;
	ATTRIBUTE_ACCESSORS(UColorDayAttributeSet, CurrentEnergy)

	UPROPERTY(BlueprintReadOnly, Category = "Energy")
	FGameplayAttributeData MaxEnergy;
	ATTRIBUTE_ACCESSORS(UColorDayAttributeSet, MaxEnergy)

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UColorDayAttributeSet, AttackPower)

	UPROPERTY(BlueprintReadOnly, Category = "Defence")
	FGameplayAttributeData ShieldPower;
	ATTRIBUTE_ACCESSORS(UColorDayAttributeSet, ShieldPower)


	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData DamageTaken;
	ATTRIBUTE_ACCESSORS(UColorDayAttributeSet, DamageTaken)

	
};
