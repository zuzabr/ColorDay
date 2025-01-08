// ZuzabrGames All rights reserved 2024


#include "Animation/PlayerLinkedAnimLayer.h"
#include "Animation/ColorDayBaseAnimInst.h"

UColorDayBaseAnimInst* UPlayerLinkedAnimLayer::GetColorDayBaseAnimInst() const
{
	return Cast<UColorDayBaseAnimInst>(GetOwningComponent()->GetAnimInstance());	
}
