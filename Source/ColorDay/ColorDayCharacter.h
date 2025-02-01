// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
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
class UDA_PlayerAbilities;

class UPlayerCombatComponent;
class UPhysicsHandleComponent;


DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AColorDayCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()


	/** Pawn mesh: 1st person view (arms; seen only by self)*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh1P; 

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	UPhysicsHandleComponent* PhysicsHandle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	UPlayerCombatComponent* CombatComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input, meta = (AllowPrivateAccess = "true"))
	float DefaultSpeed=400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input, meta = (AllowPrivateAccess = "true"))
	float SprintSpeed = 1000.0f;

	
public:
	AColorDayCharacter();

	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
	
	FORCEINLINE UColorDayAbilitySystemComp* GetColorDayAbilitySystemComp() const {return ColorDayAbilitySystemComp;}
	FORCEINLINE UColorDayAttributeSet* GetColorDayAttributeSet() const { return ColorDayAttributeSet; }
	FORCEINLINE UPlayerCombatComponent* GetCombatComponent() const { return CombatComponent; }

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

	void Interact(const FInputActionValue& Value);

	// GAS Iput for abiliities
	void AbilityInputPressed(FGameplayTag IputTag);
	void AbilityInputReleased(FGameplayTag IputTag);

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
	TSoftObjectPtr<UDA_PlayerAbilities> StartupAbilities;




private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = CharacterData, meta = (AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDataAsset;



	UPROPERTY(EditAnywhere, Category = "Interaction")
	float InteractionRange = 500.0f;

	FGameplayTag InteractionTag;

	bool bCanSprint = true;
	bool bCanCrouch = true;
	bool bCanUnCrouch = true;


	bool CanSprint();
	void SetDefaulSpeed();



};

