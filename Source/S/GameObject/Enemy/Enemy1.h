// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Enemy.h"
#include "Enemy1.generated.h"

class AExpOrb;

UCLASS()
class S_API AEnemy1 : public AEnemy
{
	GENERATED_BODY()

public:
	AEnemy1();
	virtual const FEnemyStat& GetStat() override { return Stats; };

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;
	virtual void GetDamage(const float& value) override;
	virtual void OnEnable() override;

	


	static FEnemyStat Stats;
};
