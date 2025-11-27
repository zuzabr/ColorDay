// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character/ColorCharacterBase.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "Actors/ColorInteractionInterface.h"
#include "NPCCharacter.generated.h"

class UColorDayAbilitySystemComp;
class UColorDayAttributeSet;
class UEnemyCombatComponent;
class UAbilitySystemComponent;
class UDA_EnemyAbilities;
class APatrolSplineActor;

UCLASS()
class COLORDAY_API ANPCCharacter : public AColorCharacterBase, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCCharacter();

	FORCEINLINE UColorDayAbilitySystemComp* GetColorDayAbilitySystemComp() const { return ColorDayAbilitySystemComp; }
	FORCEINLINE UColorDayAttributeSet* GetColorDayAttributeSet() const { return ColorDayAttributeSet; }
	FORCEINLINE UEnemyCombatComponent* GetCombatComponent() const { return CombatComponent; }
	FORCEINLINE APatrolSplineActor* GetPatrolPath() const { return PatrolPath; }

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void Teleport(UParticleSystem* TeleportFX);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void TeleportEnd();

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	APatrolSplineActor* PatrolPath;

private:
	FGameplayTag InteractionTag;

	void InitEnemyAbilities();

	UParticleSystemComponent* TeleportEmitter;

};
