// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/RangeBase.h"
#include "PAxe.generated.h"

class UBasic;
class UAxe;

UCLASS()
class S_API APAxe : public ARangeBase
{
	GENERATED_BODY()
public:
	APAxe();
	virtual void SetBasic(UBasic* basic) override;
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;


private:
	friend class UAxe;
	static UAxe* Basic;
};
