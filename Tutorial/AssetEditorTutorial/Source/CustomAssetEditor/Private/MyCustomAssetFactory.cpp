// Fill out your copyright notice in the Description page of Project Settings.
#include "MyCustomAssetFactory.h"

#include "MyCustomAsset.h"

UMyCustomAssetFactory::UMyCustomAssetFactory()
{
	// provide information about how to handle our asset
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UMyCustomAsset::StaticClass();
}


UObject* UMyCustomAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	// Create and return a new instance of our MyCustomAsset Object

	UMyCustomAsset* _myCustomAsset = NewObject<UMyCustomAsset>(InParent, InClass, InName, Flags);
	return _myCustomAsset;
}
