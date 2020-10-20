// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CustomAssetEditor.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = Rendering, BlueprintType)
class UCustomAssetEditor : public UObject
{
	
	GENERATED_BODY()
	~UCustomAssetEditor();
	
protected:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category=CustomAsset, meta = (DisplayName = "Test booelan"))
	bool bEnable = true;

public:
	bool GetEnabled() { return bEnable; }
};
