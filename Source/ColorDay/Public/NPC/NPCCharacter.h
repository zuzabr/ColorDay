// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "Actors/ColorInteractionInterface.h"
#include "NPCCharacter.generated.h"

class UColorDayAbilitySystemComp;
class UColorDayAttributeSet;
class UEnemyCombatComponent;
class UAbilitySystemComponent;
class UDA_EnemyAbilities;

UCLASS()
class COLORDAY_API ANPCCharacter : public ACharacter, public IAbilitySystemInterface, public IColorInteractionInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCCharacter();

	FORCEINLINE UColorDayAbilitySystemComp* GetColorDayAbilitySystemComp() const { return ColorDayAbilitySystemComp; }
	FORCEINLINE UColorDayAttributeSet* GetColorDayAttributeSet() const { return ColorDayAttributeSet; }
	FORCEINLINE UEnemyCombatComponent* GetCombatComponent() const { return CombatComponent; }

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:

	virtual void PossessedBy(AController* NewController) override;

	virtual void TryToInteractWithItem(const FGameplayTag& ColorTag) const override;
	virtual void TryToHitItem(const FGameplayTag& ColorTag, float BaseDamage = 0.f) const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UColorDayAbilitySystemComp* ColorDayAbilitySystemComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UColorDayAttributeSet* ColorDayAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AbilitySystem")
	TSoftObjectPtr<UDA_EnemyAbilities> EnemyAbilities;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UEnemyCombatComponent* CombatComponent;

private:
	FGameplayTag InteractionTag;

	void InitEnemyAbilities();

};
