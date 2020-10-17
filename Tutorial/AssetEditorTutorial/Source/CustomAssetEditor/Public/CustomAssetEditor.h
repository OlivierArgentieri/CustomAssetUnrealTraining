#pragma once

#include "CoreMinimal.h"
#include "Toolkits/IToolkitHost.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "ICustomAssetEditor.h"

class IDetailsView;
class SDockableTab;
class UMyCustomAsset;


class CUSTOMASSETEDITOR_API FCustomAssetEditor : public ICustomAssetEditor
{
public:
	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& _inTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& _inTabManager) override;

	/// <summary>
	/// edit specified asse object
	/// </summary>
	/// <param name="_mode"></param>
	/// <param name="_initToolkitHost"></param>
	/// <param name="_inMyCustomAsset"></param>
	void InitCustomAssetEditor(const EToolkitMode::Type _mode, const TSharedPtr < class IToolkitHost>& _initToolkitHost, UMyCustomAsset* _inMyCustomAsset);

	virtual ~FCustomAssetEditor();

public:
	// IToolkit interface
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }

	/** Begin ICustomAssetEditor initerface */
	virtual UMyCustomAsset* GetCustomAsset();
	virtual void SetCustomAsset(UMyCustomAsset* InCustomAsset);
	/** End ICustomAssetEditor initerface */
private:
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& _args);

	TSharedPtr<SDockableTab> PropertiesTab;

	TSharedPtr<class IDetailsView> DetailsView;

	static const FName ToolkitFName;
	static const FName PropertiesTabId;

	UMyCustomAsset* CustomAsset;
};