// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/RangeBase.h"
#include "PAxe.generated.h"

/**
 * 
 */
UCLASS()
class S_API APAxe : public ARangeBase
{
	GENERATED_BODY()
public:
	APAxe();
	inline const FProjectileData& GetData()
	{
		return Data;
	}
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;

	static FProjectileData Data;

private:
	friend class UAxe;
};
