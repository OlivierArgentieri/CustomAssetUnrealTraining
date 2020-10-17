// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MyCustomAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMASSETEDITOR_API UMyCustomAssetFactory : public UFactory
{
	GENERATED_BODY()

public:
	UMyCustomAssetFactory();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
