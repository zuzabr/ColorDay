// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ColorDay : ModuleRules
{
	public ColorDay(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
            "Core",
            "CoreUObject", 
            "Engine",
            "InputCore",
            "EnhancedInput",
            "Niagara",
            "GameplayTags",
            "GameplayTasks",
            "OnlineSubsystem",
   
            "AIModule",
            //"StateTreeModule",
            //"GameplayStateTreeModule",
            "UMG",
            "Slate"
        });

        PrivateDependencyModuleNames.AddRange(new string[]{ });

        PublicIncludePaths.AddRange(new string[] {
            "ColorDay",
            "ColorDay/Private",
            "ColorDay/Public"
        });

    }

    
}
