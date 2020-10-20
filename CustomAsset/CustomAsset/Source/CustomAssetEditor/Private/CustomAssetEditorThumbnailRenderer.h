// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "ThumbnailRendering/ThumbnailRenderer.h"
#include "CustomAssetEditorThumbnailRenderer.generated.h"

/**
 * 
 */
UCLASS(MinimalAPI)
class UCustomAssetEditorThumbnailRenderer : public UThumbnailRenderer
{
	GENERATED_BODY()
	
	//~ Begin UThumbnail render interface
	virtual bool CanVisualizeAsset(UObject* Object) override;
	virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* Viewport, FCanvas* Canvas, bool bAdditionalViewFamily) override;
	//~ Begin UThumbnail render interface

	
};
