//Copyright Bansh Games 2022, All Rights Reserved.

using System.IO;
//using UnrealBuildTool;

namespace UnrealBuildTool.Rules
{
public class AdMob : ModuleRules
{
	public AdMob(ReadOnlyTargetRules Target) : base(Target)
	{

            PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

            PublicIncludePaths.AddRange(
			new string[] {


				// ... add public include paths required here ...
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
				"CoreUObject",
				//"Slate",
                "Engine",
				//"SlateCore",


				// ... add private dependencies that you statically link with here ...
			}
			);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);


         if (Target.Platform == UnrealTargetPlatform.Android)
        {

            PrivateDependencyModuleNames.AddRange(
                new string[] {
               "Launch",
                }
                );


            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "AdMob_APL.xml"));
        }


    }
}
}