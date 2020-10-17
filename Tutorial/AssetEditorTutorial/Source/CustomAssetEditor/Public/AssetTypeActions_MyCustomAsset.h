#pragma once
#include "AssetTypeActions_Base.h"
#include "CoreMinimal.h"
#include "Toolkits/IToolkitHost.h"
/*
 * 
 */
class FAssetTypeActions_MyCustomAsset : public FAssetTypeActions_Base
{
public:

	// IAssetTypeActions interface

	virtual FText GetName() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects,	TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;
	
};