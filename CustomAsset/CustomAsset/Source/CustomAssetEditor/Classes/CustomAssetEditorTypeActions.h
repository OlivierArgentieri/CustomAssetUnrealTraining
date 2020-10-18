#pragma once
#include "AssetTypeActions_Base.h"


class FAssetTypeActions_CustomAssetEditor : public FAssetTypeActions_Base
{
public:
	FAssetTypeActions_CustomAssetEditor(){}

protected:
	//~ Begin FAssetTypeActions_RuntimeCustomAssetEditor
	virtual UClass* GetSupportedClass() const override;
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return true; };
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;
	//~ End

private:
	
	
};