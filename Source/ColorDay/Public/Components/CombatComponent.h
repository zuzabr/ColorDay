// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayAbilitySpecHandle.h"
#include "CombatComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COLORDAY_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	
	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray< FGameplayAbilitySpecHandle>& SpecHandles);

	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;

	virtual void OnHitTargetActor(AActor* HitActor);
	virtual void OnHitByActor(AActor* InstigatorActor);

protected:

	template <class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "T Template GetOwningPawn must be derived from APawn");
		return CastChecked<T>(GetOwner());
	}

	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}

	template<class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "T Template GetOwningController must be derived from AController");
		return GetOwningPawn<APawn>()->GetController<T>();
	}

private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
};
