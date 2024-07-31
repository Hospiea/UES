// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/Melee.h"
#include "PHammer.generated.h"

class UBasic;
class UHammer;

UCLASS()
class S_API APHammer : public AMelee
{
	GENERATED_BODY()
	

public:
	APHammer();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	float Timer;

private:
	static UHammer* Basic;
	friend class UHammer;
};
