#pragma once
#include "IDetailCustomization.h"

/** UI customization for URuntimeVirtualTexture */
class FCustomAssetEditorDetailsCustomization: public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();

	private:

protected:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

};
