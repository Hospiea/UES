// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Attacks/Basic/Basic.h"
#include "Chakram.generated.h"

/**
 * 
 */
UCLASS()
class S_API UChakram : public UBasic
{
	GENERATED_BODY()

public:
	UChakram(const FObjectInitializer& Init);
	virtual void Init() override;
	virtual void BasicAttack(const FVector2D& Dir) override;
	virtual void SetWeaponData() override;


private:
	friend class APChakram;
	
};
