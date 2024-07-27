// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/RangeBase.h"
#include "PThunder.generated.h"

class UStaff;
class UBasic;

UCLASS()
class S_API APThunder : public ARangeBase
{
	GENERATED_BODY()

public:
	APThunder();
	virtual void SetBasic(UBasic* basic) override;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;


private:
	static UStaff* Basic;
	friend class UStaff;
};
