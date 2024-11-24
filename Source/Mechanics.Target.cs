// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class MechanicsTarget : TargetRules
{
	public MechanicsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		
		// For Debug in shipping game
		GlobalDefinitions.Add("ALLOW_CONSOLE=1");
		GlobalDefinitions.Add("UE_WITH_CHEAT_MANAGER=1");
		
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("Mechanics");

		// UE_LOG View
		bUseLoggingInShipping = true;
		BuildEnvironment = TargetBuildEnvironment.Unique;
	}
}
