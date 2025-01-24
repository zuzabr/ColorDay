// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "ColorDayCoreTypes.h"
#include "GameplayAbilitySpecHandle.h"
#include "CombatComponent.generated.h"

class AColorDayGun;
class AColorDayActor;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COLORDAY_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void RegisterWeapon(FGameplayTag WeaponTag, AColorDayGun* Weapon, bool bEquipped = false);

	UFUNCTION(BlueprintCallable, Category = "Combat")
	AColorDayGun* GetCarriedWeaponByTag(FGameplayTag WeaponTag) const;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	AColorDayGun* GetEquippedWeapon() const;



	

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray< FGameplayAbilitySpecHandle>& SpecHandles);

	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;

	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	FGameplayTag EquippedWeaponTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FItemInputData CarringItemData;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

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
	TMap<FGameplayTag, AColorDayGun*> CarriedWeaponMap;
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
};
