#include "CustomAssetEditorModule.h"
 
#include "AssetToolsModule.h"
#include "CustomAssetEditor.h"
#include "CustomAssetEditorTypeActions.h"
#include "IAssetTools.h"
#include "IPlacementModeModule.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

#define LOCTEXT_NAMESPACE "CustomAssetEditorModule"


class FCustomAssetEditorModule : public FWorkflowTabFactory
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override;
	
private:
	void OnPlacementModeRefresh(FName _categoryName);
};

IMPLEMENT_MODULE(FCustomAssetEditorModule, CustomAssetEditor);


FCustomAssetEditorModule(TSharedPtr<class FAssetEditorToolkit> InHostingApp)
	: FWorkflowTabFactory(TEXT("PersonaSequenceRecorderSettings"), InHostingApp)
{
	TabLabel = LOCTEXT("AnimationRecordingSettings", "Recording Settings");
	TabIcon = FSlateIcon(FEditorStyle::GetStyleSetName(), "SequenceRecorder.TabIcon");
	ViewMenuDescription = LOCTEXT("AnimationRecordingSettings", "Recording Settings");
	ViewMenuTooltip = LOCTEXT("AnimationRecordingSettings_Tooltip", "Settings for animation recording");

	StructOnScope = MakeShared<FStructOnScope>(FAnimationRecordingSettings::StaticStruct(), (uint8*)&GetMutableDefault<USequenceRecorderSettings>()->DefaultAnimationSettings);
}

void FCustomAssetEditorModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("Hey"));
	IAssetTools& _assetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	_assetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_CustomAssetEditor));

	//FPropertyEditorModule& _propertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	//_propertyModule.RegisterCustomClassLayout("CustomAssetEditor", FOnGetDetailCustomizationInstance::CreateStatic(&FCustomAssetEditorDetailsCustomization::MakeInstance));

	// todo
	FPlacementCategoryInfo Info(LOCTEXT("TestCategoryName", "Test Category"), "TestCategory", TEXT("PMTestCategory"));

	IPlacementModeModule::Get().RegisterPlacementCategory(Info);

	//IPlacementModeModule::Get().RegisterPlaceableItem(Info.UniqueHandle, MakeShareable(new FPlaceableItem(nullptr, FAssetData(UCustomAssetEditor::StaticClass()))));
	
//	IPlacementModeModule& _placementModeModule = IPlacementModeModule::Get();
//	_placementModeModule.OnPlacementModeCategoryRefreshed().AddRaw(this, &FCustomAssetEditorModule::OnPlacementModeRefresh);
	
		
	//
	//	_placementModeModule.OnPlacementModeCategoryRefreshed().AddRaw(this, &FCustomAssetEditorModule::OnPlacementModeRefresh);

	//UThumbnailManager::Get().RegisterCustomRenderer(UCustomAssetEditor::StaticClass(), UCustomAssetEditorThumbnailRenderer::StaticClass());
	
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