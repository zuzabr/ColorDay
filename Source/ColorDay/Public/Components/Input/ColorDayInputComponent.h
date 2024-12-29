// ZuzabrGames All rights reserved 2024

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "ColorDayInputComponent.generated.h"



UCLASS()
class COLORDAY_API UColorDayInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
};

template<class UserObject, typename CallbackFunc>
inline void UColorDayInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{	
	checkf(InInputConfig, TEXT("Input config Data is null, cannot proceed with binding"));
	if (auto FoundAction = InInputConfig->FindNativeInputActionByTag(InTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}
