using UnrealBuildTool;

public class DemoEditorExtensionsRuntime : ModuleRules
{
    public DemoEditorExtensionsRuntime(ReadOnlyTargetRules _target) : base(_target)
    {
        PublicDependencyModuleNames.AddRange(
            new string[] 
                {
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "Slate"
                }
            );
    }
}