// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Bomberman2025 : ModuleRules
{
	public Bomberman2025(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
