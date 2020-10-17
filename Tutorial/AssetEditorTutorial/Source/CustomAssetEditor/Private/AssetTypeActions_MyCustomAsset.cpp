#include "AssetTypeActions_MyCustomAsset.h"
#include "MyCustomAsset.h"
#include "ICustomAssetEditorModule.h"


#define LOCTEXT_NAMESPACE "AssetTypeActions_MyCustomAsset"

FText FAssetTypeActions_MyCustomAsset::GetName() const
{
	return NSLOCTEXT("AssetTypeActions_MyCustomAsset", "AssetTypeActions_MyCustomAsser", "MyCustomAsset");
}

UClass* FAssetTypeActions_MyCustomAsset::GetSupportedClass() const
{
	return UMyCustomAsset::StaticClass();
}

FColor FAssetTypeActions_MyCustomAsset::GetTypeColor() const
{
	return FColor::Magenta;
}

uint32 FAssetTypeActions_MyCustomAsset::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

void FAssetTypeActions_MyCustomAsset::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type _mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for(auto _objIt = InObjects.CreateConstIterator(); _objIt; ++_objIt)
	{
		auto _myCustomAsset = Cast<UMyCustomAsset>(*_objIt);
		if(_myCustomAsset != nullptr)
		{
			ICustomAssetEditorModule* _customAssetEditorModule = &FModuleManager::LoadModuleChecked<ICustomAssetEditorModule>("CustomAssetEditor");
			_customAssetEditorModule->CreateCustomAssetEditor(_mode, EditWithinLevelEditor, _myCustomAsset);
		}
	}
}
#undef LOCTEXT_NAMESPACE