// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ColorDayBaseAnimInst.generated.h"

class AColorDayCharacter;
class UCharacterMovementComponent;

UCLASS()
class COLORDAY_API UColorDayBaseAnimInst : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	AColorDayCharacter* OwningChar;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComp;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category="AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bIsInAir;

};
