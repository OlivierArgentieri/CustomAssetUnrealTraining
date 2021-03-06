#include "CustomAssetEditor/Classes/CustomAssetEditorTypeActions.h"

#include "CustomAssetEditor.h"


#define LOCTEXT_NAMESPACE "CustomAssetEditor"
DEFINE_LOG_CATEGORY(MyMenuLog)

UClass* FAssetTypeActions_CustomAssetEditor::GetSupportedClass() const
{
	return UCustomAssetEditor::StaticClass();
}

FText FAssetTypeActions_CustomAssetEditor::GetName() const
{
	return LOCTEXT("AssetTypeActions_CustomAssetEditor", "Custom Asset Editor");
}

FColor FAssetTypeActions_CustomAssetEditor::GetTypeColor() const
{
	return FColor(128, 128, 128);
}


uint32 FAssetTypeActions_CustomAssetEditor::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

void FAssetTypeActions_CustomAssetEditor::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddMenuEntry(
		LOCTEXT("RuntimeVirtualTexture_FindMaterials", "Find Materials Using This"),
		LOCTEXT("RuntimeVirtualTexture_FindMaterialsTooltip", "Finds all materials that use this material in the content browser."),
		FSlateIcon(),
		FUIAction(
			FUIAction(FExecuteAction::CreateRaw(this, &FAssetTypeActions_CustomAssetEditor::CallbackTest))
		)
	);
	
}

void FAssetTypeActions_CustomAssetEditor::CallbackTest()
{
	UE_LOG(MyMenuLog, Log, TEXT("Action 1!"));
}


#undef LOCTEXT_NAMESPACE
