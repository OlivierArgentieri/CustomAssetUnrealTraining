using UnrealBuildTool;

public class DemoEditorExtensionsEditor : ModuleRules
{
    public DemoEditorExtensionsEditor(ReadOnlyTargetRules _target) : base(_target)
    {
        PublicDependencyModuleNames.AddRange(
            new string[]
                {
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "Slate",
                    "UnrealEd",
                    "DemoEditorExtensionsEditor",
                }
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
                {
                    "InputCore",
                    "SlateCore",
                    "PropertyEditor",
                    "LevelEditor"
                }
            );
    }
}