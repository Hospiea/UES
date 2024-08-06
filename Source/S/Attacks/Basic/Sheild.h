// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Attacks/Basic/Basic.h"
#include "Sheild.generated.h"

class APSheild;

UCLASS()
class S_API USheild : public UBasic
{
	GENERATED_BODY()
	
public:
	USheild(const FObjectInitializer& Init);
	virtual void Init() override;
	virtual void BasicAttack(const FVector2D& Dir) override;
	virtual void SetWeaponData() override;

	UPROPERTY()
	TArray<TObjectPtr<APSheild>> Shields;

	UPROPERTY()
	uint8 counter;

private:
	friend class APSheild;
};
