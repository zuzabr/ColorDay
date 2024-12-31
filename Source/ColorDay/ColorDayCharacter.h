// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "AbilitySystemInterface.h"
#include "ColorDayCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;

class UInputAction;
class UInputMappingContext;
class UDataAsset_InputConfig;
struct FInputActionValue;

class UColorDayAbilitySystemComp;
class UColorDayAttributeSet;
class UDA_StartupHeroAbilities;

class UCombatComponent;


DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AColorDayCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()


	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input, meta = (AllowPrivateAccess = "true"))
	float DefaultSpeed=600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input, meta = (AllowPrivateAccess = "true"))
	float SprintSpeed = 2000.0f;

	
public:
	AColorDayCharacter();

	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
	
	FORCEINLINE UColorDayAbilitySystemComp* GetColorDayAbilitySystemComp() const {return ColorDayAbilitySystemComp;}
	FORCEINLINE UColorDayAttributeSet* GetColorDayAttributeSet() const { return ColorDayAttributeSet; }
	FORCEINLINE UCombatComponent* GetCombatComponent() const { return CombatComponent; }

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for crouching input */
	void CrouchToggle(const FInputActionValue& Value);

	void Sprint(const FInputActionValue& Value);
	void StopSprint(const FInputActionValue& Value);

	// APawn interface
	virtual void NotifyControllerChanged() override;
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	virtual void PossessedBy(AController* NewController) override;
	// End of APawn interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UColorDayAbilitySystemComp* ColorDayAbilitySystemComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UColorDayAttributeSet* ColorDayAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AbilitySystem")
	TSoftObjectPtr<UDA_StartupHeroAbilities> StartupAbilities;

	
		


private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = CharacterData, meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UCombatComponent* CombatComponent;

	bool bCanSprint = true;
	bool bCanCrouch = true;
	bool bCanUnCrouch = true;


	bool CanSprint();
	void SetDefaulSpeed();



};

