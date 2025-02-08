//Copyright Bansh Games 2022, All Rights Reserved.

using UnrealBuildTool;

public class AdsEditor : ModuleRules
{
	public AdsEditor(ReadOnlyTargetRules Target) : base(Target)
	{

        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
			new string[] {

				// ... add public include paths required here ...
			}
			);


		PrivateIncludePaths.AddRange(
			new string[] {

				// ... add other private include paths required here ...
			}
			);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "CoreUObject",
                "InputCore",
                "UnrealEd",
                "Engine",
                //"SlateCore",
                "EditorStyle",
                "EditorWidgets",
                "DesktopWidgets",
                "PropertyEditor",
                "SharedSettingsWidgets",
                "SourceControl",
                "AndroidRuntimeSettings",
                "AndroidDeviceDetection",
                "TargetPlatform",
                "RenderCore",
                "MaterialShaderQualitySettings",
            }
			);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
