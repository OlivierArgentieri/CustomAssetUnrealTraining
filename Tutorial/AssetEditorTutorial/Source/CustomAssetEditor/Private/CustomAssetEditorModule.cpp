#include "CustomAssetEditor/Public/CustomAssetEditorModule.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"

IMPLEMENT_GAME_MODULE(FCustomAssetEditorModule, CustomAssetEditor);

#define LOCTEXT_NAMESPACE "FCustomAssetEditorModule"
void FCustomAssetEditorModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("StartupModule() called"));
}


void FCustomAssetEditorModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE