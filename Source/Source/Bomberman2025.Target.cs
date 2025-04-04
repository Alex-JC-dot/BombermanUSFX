// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Bomberman2025Target : TargetRules
{
	public Bomberman2025Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
        bUseUnityBuild = true;
        bUseSharedPCHs = true;
        ExtraModuleNames.Add("Bomberman2025");
	}
}
