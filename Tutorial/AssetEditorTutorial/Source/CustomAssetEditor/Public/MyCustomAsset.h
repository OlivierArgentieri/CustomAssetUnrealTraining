// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyCustomAsset.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMASSETEDITOR_API UMyCustomAsset : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, Category = MyCustomAsset)
	FString Description;


	UPROPERTY(VisibleAnywhere, Category = MyCustomAsset)
	bool bIsActive;


	
};
