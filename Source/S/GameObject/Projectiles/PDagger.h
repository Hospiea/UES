// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/RangeBase.h"
#include "PDagger.generated.h"

class UDagger;

UCLASS()
class S_API APDagger : public ARangeBase
{
	GENERATED_BODY()
	
public:
	APDagger();

protected:
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;


private:
	static UDagger* Basic;
	friend class UDagger;
};
