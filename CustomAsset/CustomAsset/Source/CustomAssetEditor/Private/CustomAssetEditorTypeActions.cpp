#include "CustomAssetEditor/Classes/CustomAssetEditorTypeActions.h"

#include "CustomAssetEditor.h"

#define LOCTEXT_NAMESPACE "CustomAssetEditor"


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
	// todo 
}


#undef LOCTEXT_NAMESPACE
