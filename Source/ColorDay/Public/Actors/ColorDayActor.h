// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actors/ColorInteractionInterface.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "ColorDayCoreTypes.h"
#include "ColorDayActor.generated.h"

class UASC_ColorActor;
class UColorDayAttributeSet;

UCLASS()
class COLORDAY_API AColorDayActor : public AActor, public IColorInteractionInterface, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColorDayActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	UMaterialInstanceDynamic* DynamicMaterial;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	void GrantAbilities(int32 ApplyLevel = 1);

	FORCEINLINE UASC_ColorActor* GetColorDayAbilitySystemComp() const { return ASC_ColorActor; }
	FORCEINLINE UColorDayAttributeSet* GetColorDayAttributeSet() const { return ColorDayAttributeSet; }

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AbilitySystem|Abilities")
	bool HasPhysics = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;


	virtual void TryToInteractWithItem(const FGameplayTag& ColorTag) const override;
	virtual void TryToHitItem(const FGameplayTag& ColorTag) const override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UASC_ColorActor* ASC_ColorActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UColorDayAttributeSet* ColorDayAttributeSet;

	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem|Abilities")
	TArray<FColorActorAbilitySet> ColorActorAbilitySet;
	
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem|Abilities")
	bool ActiveFromStart = true;

	


};
