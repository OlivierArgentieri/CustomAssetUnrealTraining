#include "CustomAssetEditorDetailsCustomization.h"
#include "DetailLayoutBuilder.h"

TSharedRef<IDetailCustomization> FCustomAssetEditorDetailsCustomization::MakeInstance()
{
	return MakeShareable(new FCustomAssetEditorDetailsCustomization);
}


void FCustomAssetEditorDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	
}
