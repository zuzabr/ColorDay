// ZuzabrGames All rights reserved 2024


#include "Animation/ColorDayBaseAnimInst.h"
#include "ColorDay/ColorDayCharacter.h"
#include "Character/ColorCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UColorDayBaseAnimInst::NativeInitializeAnimation()
{
	OwningChar = Cast<AColorCharacterBase>(TryGetPawnOwner());
	if (!OwningChar) return;
	OwningMovementComp = OwningChar->GetCharacterMovement();
}

void UColorDayBaseAnimInst::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningChar || !OwningMovementComp) return;

	GroundSpeed = OwningChar->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComp->GetCurrentAcceleration().SizeSquared2D() > 0.f;
	bIsInAir = OwningMovementComp->IsFalling();
}
