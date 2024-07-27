// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/RangeBase.h"
#include "PSpear.generated.h"

class UBasic;
class USpear;

UCLASS()
class S_API APSpear : public ARangeBase
{
	GENERATED_BODY()
public:
	APSpear();
	virtual void SetBasic(UBasic* basic) override;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	

private:
	friend class USpear;
	static USpear* Basic;
};
