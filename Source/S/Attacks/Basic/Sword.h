// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Attacks/Basic/Basic.h"
#include "Sword.generated.h"


UCLASS()
class S_API USword : public UBasic
{
	GENERATED_BODY()
	
public:
	USword(const FObjectInitializer& Init);
	virtual void Init() override;
	virtual void BasicAttack(const FVector2D& Dir) override;
	virtual void SetWeaponData() override;
	virtual inline FProjectileData& GetData() override
	{
		return Data;
	}




private:
	friend class APSword;
};
