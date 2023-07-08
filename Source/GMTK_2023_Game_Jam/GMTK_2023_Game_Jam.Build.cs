// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GMTK_2023_Game_Jam : ModuleRules
{
	public GMTK_2023_Game_Jam(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
    }
}
