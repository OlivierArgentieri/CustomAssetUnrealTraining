#include "CustomAssetEditorModule.h"

#include "CustomAssetEditorModule.h"



#include "AssetToolsModule.h"
#include "CustomAssetEditorTypeActions.h"
#include "IAssetTools.h"
#include "PropertyEditorModule.h"
#include "IPlacementModeModule.h"
#define LOCTEXT_NAMESPACE "CustomAssetEditorModule"


class FCustomAssetEditorModule : public ICustomAssetEditorModule
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override;
	
private:
	void OnPlacementModeRefresh(FName _categoryName);
};

IMPLEMENT_MODULE(FCustomAssetEditorModule, CustomAssetEditor);

void FCustomAssetEditorModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("Hey"));
	IAssetTools& _assetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	_assetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_CustomAssetEditor));

	FPropertyEditorModule& _propertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	//_propertyModule.RegisterCustomClassLayout("CustomAssetEditor", FOnGetDetailCustomizationInstance::CreateStatic(&FCustomAssetEditorModule))
}

void FCustomAssetEditorModule::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("ShutdownModule"));
}

bool FCustomAssetEditorModule::SupportsDynamicReloading()
{
	return false;
}


void FCustomAssetEditorModule::OnPlacementModeRefresh(FName _categoryName)
{
	static FName _volumeName = FName(TEXT("Tests"));

	if (_categoryName != _volumeName) return;

	IPlacementModeModule& _placementModeModule = IPlacementModeModule::Get();
//	_placementModeModule.RegisterPlaceableItem(_categoryName, MakeShareable(new FPlaceableItem(nullptr, FAssetData(ARuntimeCustomAssetEditor::StaticClass()))));

	
}

#undef LOCTEXT_NAMESPACE