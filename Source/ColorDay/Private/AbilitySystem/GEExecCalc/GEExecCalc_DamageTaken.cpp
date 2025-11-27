// ZuzabrGames All rights reserved 2024


#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"
#include "AbilitySystem/ColorDayAttributeSet.h"
#include "ColorDayGameplayTags.h"
#include "ColorDayDebugHelper.h"

struct FColorDayDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(ShieldPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)

	FColorDayDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UColorDayAttributeSet, AttackPower,Source, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UColorDayAttributeSet, ShieldPower, Target, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UColorDayAttributeSet, DamageTaken, Target, false)
	}
};

static const FColorDayDamageCapture& GetColorDayDamageCapture()
{
	static FColorDayDamageCapture ColorDayDamageCapture;
	return ColorDayDamageCapture;
}

UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{
	RelevantAttributesToCapture.Add(GetColorDayDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetColorDayDamageCapture().ShieldPowerDef);
	RelevantAttributesToCapture.Add(GetColorDayDamageCapture().DamageTakenDef);
}

void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();
	
	EffectSpec.GetContext().GetSourceObject();
	EffectSpec.GetContext().GetAbility();

	EffectSpec.GetContext().GetEffectCauser();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	float SourceAttackPower = 0.f;
	float TargetDefencePower = 0.f;
	float BaseDamage = 0.f;

	

	for (const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitude.Key.MatchesTagExact(ColorDayGameplayTags::Shared_Damage))
		{
			BaseDamage = TagMagnitude.Value;
		}
	}

	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetColorDayDamageCapture().AttackPowerDef, EvaluateParameters, SourceAttackPower);
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetColorDayDamageCapture().ShieldPowerDef, EvaluateParameters, TargetDefencePower);

	const float FinalDamage = BaseDamage * SourceAttackPower / TargetDefencePower;
	Debug::Print(TEXT("FinalDamage"), FinalDamage);

	if (FinalDamage > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(
			GetColorDayDamageCapture().DamageTakenProperty,
			EGameplayModOp::Override,
			FinalDamage));
	}
}
