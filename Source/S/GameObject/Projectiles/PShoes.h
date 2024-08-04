// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/Melee.h"
#include "PShoes.generated.h"

class UBasic;
class UShoes;

UCLASS()
class S_API APShoes : public AMelee
{
	GENERATED_BODY()
	
public:
	APShoes();
	virtual void SetBasic(UBasic* basic) override;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;
	virtual void OnEnable() override;


	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:
	friend class UShoes;
	static UShoes* Basic;
	UPROPERTY()
	float Timer;
};
