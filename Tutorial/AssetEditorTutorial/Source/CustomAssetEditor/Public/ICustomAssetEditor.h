#pragma once

#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"

class UMyCustomAsset;

class ICustomAssetEditor: public FAssetEditorToolkit
{
	/* Retrieves the current custom asset. */
	virtual UMyCustomAsset* GetCustomAsset() = 0;

	virtual void SetCustomAsset(UMyCustomAsset* _inCustomAsset) = 0;
};