using UnrealBuildTool;


public class CustomAssetEditor : ModuleRules
{
    public CustomAssetEditor(ReadOnlyTargetRules _target) : base(_target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "Slate",
            "UnrealEd",
            "CustomAssetEditor"
        });


        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "AppFramework",
            "AssetRegistry",
            "Core",
            "CoreUObject",
            "DesktopPlatform",
            "DesktopWidgets",
            "EditorStyle",
            "Engine",
            "InputCore",
            "MaterialEditor",
            "PlacementMode",
            "PropertyEditor",
            "RenderCore",
            "Renderer",
            "RHI",
            "Slate",
            "SlateCore",
            "UnrealEd",
        });

        PrivateIncludePaths.AddRange(new string[]
        {
            "CustomAssetEditor/Private"
        });

        PrivateIncludePaths.AddRange(new string[]
        {
            "CustomAssetEditor/Public"
        });
    }
}