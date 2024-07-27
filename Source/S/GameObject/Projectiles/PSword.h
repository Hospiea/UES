// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/Melee.h"
#include "PSword.generated.h"

class UBasic;
class USword;

UCLASS()
class S_API APSword : public AMelee
{
	GENERATED_BODY()

public:
	APSword();
	virtual void SetBasic(UBasic* basic) override;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;


	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:
	friend class USword;
	static USword* Basic;
};
