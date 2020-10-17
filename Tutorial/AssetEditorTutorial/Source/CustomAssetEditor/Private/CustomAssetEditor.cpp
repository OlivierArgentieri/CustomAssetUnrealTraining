#include "CustomAssetEditor.h"
#include "Modules/ModuleManager.h"
#include "EditorStyleSet.h"
#include "Widgets/Docking/SDockTab.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "Editor.h"

#include "ICustomAssetEditorModule.h"

#define LOCTEXT_NAMESPACE "CustomAssetEditor"


const FName FCustomAssetEditor::ToolkitFName(TEXT("CustomAssetEditor"));
const FName FCustomAssetEditor::PropertiesTabId(TEXT("CustomAssetEditor_Properties"));

void FCustomAssetEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& _inTabManager)
{
	WorkspaceMenuCategory = _inTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_CustomAssetEditor", "Custom Asset Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(_inTabManager);

	_inTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FCustomAssetEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FCustomAssetEditor::UnregisterTabSpawners(const TSharedRef<FTabManager>& _inTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(_inTabManager);
	_inTabManager->UnregisterTabSpawner(PropertiesTabId);
}

TSharedRef<SDockTab> FCustomAssetEditor::SpawnPropertiesTab(const FSpawnTabArgs& _args)
{
	// 
	check(_args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tab.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];
	
	
}

FName FCustomAssetEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FCustomAssetEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "Custom Asset Editor");
}

FText FCustomAssetEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "Custom Asset Editor");
}

FString FCustomAssetEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FCustomAssetEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UMyCustomAsset* FCustomAssetEditor::GetCustomAsset()
{
	return CustomAsset;
}

void FCustomAssetEditor::SetCustomAsset(UMyCustomAsset* _inCustomAsset)
{
	CustomAsset = _inCustomAsset;
}

void FCustomAssetEditor::InitCustomAssetEditor(const EToolkitMode::Type _mode, const TSharedPtr<IToolkitHost>& _initToolkitHost, UMyCustomAsset* _inMyCustomAsset)
{
	// Cache some values that will be used for our details view arguments
	const bool bIsUpdatable = false;
	//const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	// Set this InCustomAsset as our editing asset
	SetCustomAsset(_inMyCustomAsset);

	// Retrieve the property editor module and assign properties to DetailsView
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	// Create the layout of our custom asset editor
	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_CustomAssetEditor_Layout_v1")
		->AddArea
		(
			// Create a vertical area and spawn the toolbar
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				// Split the tab and pass the tab id to the tab spawner
				FTabManager::NewSplitter()
				->Split
				(
					FTabManager::NewStack()
					->AddTab(PropertiesTabId, ETabState::OpenedTab)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	// Initialize our custom asset editor
	FAssetEditorToolkit::InitAssetEditor(
		_mode,
		_initToolkitHost,
		CustomAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)_inMyCustomAsset);

	// Set the asset we are editing in the details view
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FCustomAssetEditor::~FCustomAssetEditor()
{
	DetailsView.Reset();
	PropertiesTab.Reset();
}

#undef LOCTEXT_NAMESPACE