// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/RangeBase.h"
#include "PThunder.generated.h"

/**
 * 
 */
UCLASS()
class S_API APThunder : public ARangeBase
{
	GENERATED_BODY()

public:
	APThunder();
	inline const WeaponData& GetData()
	{
		return Data;
	}

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;

	static WeaponData Data;

private:
	friend class UStaff;
};
