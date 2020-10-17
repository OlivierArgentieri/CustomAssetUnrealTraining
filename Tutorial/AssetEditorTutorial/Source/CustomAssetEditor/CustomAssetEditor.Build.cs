using UnrealBuildTool;

public class CustomAssetEditor : ModuleRules
{
    public CustomAssetEditor(ReadOnlyTargetRules _target) : base(_target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
                 {
                     "Core",
                     "CoreUObject",
                     "Engine",
                     "InputCore",
                     "UnrealEd",
                 }
            );

        PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "CustomAssetEditor"
                }
            );

        PublicIncludePaths.AddRange(
                new string[]
                {
                    "CustomAssetEditor/Public"
                }
            );

        PrivateIncludePaths.AddRange(
            new string[]
            {
                "CustomAssetEditor/Private"
            }
        );
    }
}