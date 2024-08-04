// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Enemy.h"
#include "Enemy3.generated.h"

/**
 * 
 */
UCLASS()
class S_API AEnemy3 : public AEnemy
{
	GENERATED_BODY()
	
public:
	AEnemy3();
	virtual const FEnemyStat& GetStat() override { return Stats; };


protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;
	virtual void GetDamage(const float& value) override;
	virtual void OnEnable() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setting")
	float Distance;


	static FEnemyStat Stats;
};
