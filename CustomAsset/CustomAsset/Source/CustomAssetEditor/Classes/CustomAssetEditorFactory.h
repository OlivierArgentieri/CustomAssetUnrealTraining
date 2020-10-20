#pragma once
#include "CoreMinimal.h"

#include "UObject/ObjectMacros.h"
#include "Factories/Factory.h"
#include "CustomAssetEditorFactory.generated.h"

UCLASS(HideCategories=Object)
class UCustomAssetEditorFactory : public UFactory
{
	GENERATED_BODY()

public:
	explicit UCustomAssetEditorFactory(const FObjectInitializer& ObjectInitializer);

	virtual bool ShouldShowInNewMenu() const override;
	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
	
};