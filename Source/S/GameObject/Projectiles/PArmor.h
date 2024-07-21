// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/Melee.h"
#include "PArmor.generated.h"

/**
 * 
 */
UCLASS()
class S_API APArmor : public AMelee
{
	GENERATED_BODY()
	
public:
	APArmor();
	inline const WeaponData& GetData()
	{
		return Data;
	}

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;


	static WeaponData Data;

	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:
	friend class UArmor;
};
