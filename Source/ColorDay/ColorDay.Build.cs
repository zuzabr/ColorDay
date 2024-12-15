// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ColorDay : ModuleRules
{
	public ColorDay(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Niagara" });

        PublicIncludePaths.AddRange(new string[]
        {
        //    "Shooter/Public/Weapon/Effects",
			"C:/Program Files/Epic Games/UE_5.5/Engine/Plugins/FX/Niagara/Source/Niagara/Public"

        });
    }

    
}
