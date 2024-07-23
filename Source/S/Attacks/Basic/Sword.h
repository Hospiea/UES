// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Attacks/Basic/Basic.h"
#include "GameObject/Projectiles/PSword.h"
#include "Sword.generated.h"


UCLASS()
class S_API USword : public UBasic
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	virtual void BasicAttack(const FVector2D& Dir) override;
	virtual void SetWeaponData() override;

	virtual uint8& GetLevel() override { return APSword::Level; }


protected:
	
};
