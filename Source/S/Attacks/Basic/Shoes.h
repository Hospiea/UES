// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Attacks/Basic/Basic.h"
#include "Shoes.generated.h"

/**
 * 
 */
UCLASS()
class S_API UShoes : public UBasic
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	virtual void BasicAttack(const FVector2D& Dir) override;
	virtual void SetWeaponData() override;


private:
	friend class APShoes;
};
