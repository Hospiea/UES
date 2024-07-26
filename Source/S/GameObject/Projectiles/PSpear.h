// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/RangeBase.h"
#include "PSpear.generated.h"

/**
 * 
 */
UCLASS()
class S_API APSpear : public ARangeBase
{
	GENERATED_BODY()
public:
	APSpear();
	inline const FProjectileData& GetData()
	{
		return Data;
	}

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	
	inline static uint8 Level = 0;
	static FProjectileData Data;

private:
	friend class USpear;
};
