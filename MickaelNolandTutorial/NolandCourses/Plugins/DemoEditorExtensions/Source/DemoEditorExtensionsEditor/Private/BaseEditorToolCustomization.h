#pragma once

#include "IDetailCustomization.h"


class FBaseEditorToolCustomization : public IDetailCustomization
{
public:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

	static TSharedRef<IDetailCustomization> MakeInstance();
//	static FReply ExecuteToolCommand(IDetailLayoutBuilder* _detailBuilder, UFunction* _methodToExecute); todo
};
