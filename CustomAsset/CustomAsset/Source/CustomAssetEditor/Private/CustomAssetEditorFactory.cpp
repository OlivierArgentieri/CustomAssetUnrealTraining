#include "CustomAssetEditorFactory.h"

#include "CustomAssetEditor.h"

UCustomAssetEditorFactory::UCustomAssetEditorFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UCustomAssetEditor::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

bool UCustomAssetEditorFactory::ShouldShowInNewMenu() const
{
	return true;
}

UObject* UCustomAssetEditorFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	//SupportedClass = UCustomAssetEditor::StaticClass();
	//bCreateNew = true;
	//bEditAfterNew = true;
	return NewObject<UCustomAssetEditor>(InParent, InClass, InName, Flags);
}
