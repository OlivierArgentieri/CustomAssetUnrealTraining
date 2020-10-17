#include "DemoEditorExtensionsEditorPrivatePCH.h"
#include "BaseEditorToolCustomization.h"
#include "PropertyEditing.h"


#define LOCTEXT_NAMESPACE "BaseToolEditor"

void FBaseEditorToolCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TSet<UClass*> _classes;

	TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;
	DetailBuilder.GetObjectsBeingCustomized(ObjectsBeingCustomized);

	for(auto _weakObject : ObjectsBeingCustomized)
	{
		if(UObject* instance = _weakObject.Get())
		{
			_classes.Add(instance->GetClass());

		}
	}
}
