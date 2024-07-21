// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/Melee.h"
#include "PSheild.generated.h"

/**
 * 
 */
UCLASS()
class S_API APSheild : public AMelee
{
	GENERATED_BODY()

public:
	APSheild();
	inline const FProjectileData& GetData()
	{
		return Data;
	}

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;


	static FProjectileData Data;

	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:
	friend class USheild;
};
