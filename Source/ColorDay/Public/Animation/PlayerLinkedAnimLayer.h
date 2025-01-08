// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "Animation/ColorDayBaseAnimInst.h"
#include "PlayerLinkedAnimLayer.generated.h"

class UColorDayBaseAnimInst;

UCLASS()
class COLORDAY_API UPlayerLinkedAnimLayer : public UColorDayBaseAnimInst
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UColorDayBaseAnimInst* GetColorDayBaseAnimInst() const;
};
