#pragma once


#include "AssetToolsModule.h"
#include "CustomAssetEditor.h"
#include "IAssetTypeActions.h"
#include "ICustomAssetEditorModule.h"
#include "Modules/ModuleManager.h"


class IAssetTools;
const FName CustomAssetEditorAppIdentifier = FName(TEXT("CustomAssetEditorApp"));

#define LOCTEXT_NAMESPACE = "FCustomAssetEditorModule"


/**
 * Custom Asset editor module
 */
class FCustomAssetEditorModule : public ICustomAssetEditorModule
{
public:
	// constructor
	FCustomAssetEditorModule() {}

	// GetExtensibility manager for outside entities to exented custom asset editors menu and toolbars
	virtual TSharedPtr<FExtensibilityManager> GetMenuExtensibilityManager() override { return menuExtensibilityManager; }
	virtual TSharedPtr<FExtensibilityManager> GetToolBarExtensibilityManager() override { return ToolBarExtensibilityManager; }

	// module method
	virtual void StartupModule() override
	{
		menuExtensibilityManager = MakeShareable(new FExtensibilityManager);
		ToolBarExtensibilityManager = MakeShareable(new FExtensibilityManager);

		//IAssetToolkit
	}

	virtual void ShutdownModule() override
	{
		menuExtensibilityManager.Reset();
		ToolBarExtensibilityManager.Reset();

		if(FModuleManager::Get().IsModuleLoaded("AssetTools"))
		{
			// unregister our custom created assets from the assetTools
			IAssetTools& _assetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
			for(int32 i=0; i < CreatedAssetTypeActions.Num(); ++i)
			{
				_assetTools.UnregisterAssetTypeActions(CreatedAssetTypeActions[i].ToSharedRef());
			}
			CreatedAssetTypeActions.Empty();
		}
	}

	virtual TSharedRef<ICustomAssetEditor> CreateCustomAssetEditor(const EToolkitMode::Type _mode, const TSharedPtr<IToolkitHost>& _initToolkitHost, UMyCustomAsset* _customAsset) override
	{
		TSharedRef<FCustomAssetEditor> _newCustomAssetEditor(new FCustomAssetEditor());
		_newCustomAssetEditor->InitCustomAssetEditor(_mode, _initToolkitHost, _customAsset);

		return _newCustomAssetEditor;
	}
	
private:
	TSharedPtr<FExtensibilityManager> menuExtensibilityManager;
	TSharedPtr<FExtensibilityManager> ToolBarExtensibilityManager;

	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;
};
IMPLEMENT_GAME_MODULE(FCustomAssetEditorModule, CustomAssetEditor);