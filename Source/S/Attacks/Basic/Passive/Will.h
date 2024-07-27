// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Attacks/Basic/Basic.h"
#include "Will.generated.h"

/**
 * 
 */
UCLASS()
class S_API UWill : public UBasic
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	virtual uint8& GetLevel() override { return Level; };


protected:
	uint8 Level;
};
