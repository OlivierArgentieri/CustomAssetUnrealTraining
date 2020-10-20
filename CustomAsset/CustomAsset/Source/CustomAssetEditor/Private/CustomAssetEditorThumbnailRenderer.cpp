// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAssetEditorThumbnailRenderer.h"
#include "CustomAssetEditor.h"


bool UCustomAssetEditorThumbnailRenderer::CanVisualizeAsset(UObject* Object)
{
	UCustomAssetEditor* _customAssetEditor = Cast<UCustomAssetEditor>(Object);

	return _customAssetEditor->GetEnabled();
	
}

void UCustomAssetEditorThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* Viewport, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	
}
