// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/Melee.h"
#include "PSword.generated.h"



UCLASS()
class S_API APSword : public AMelee
{
	GENERATED_BODY()

public:
	APSword();
	inline const WeaponData& GetData()
	{
		return Data;
	}

protected:
	virtual void BeginPlay() override;
	static WeaponData Data;

	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
