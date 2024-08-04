// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/GameObjects.h"
#include "HitEffect.generated.h"

/**
 * 
 */
UCLASS()
class S_API AHitEffect : public AGameObjects
{
	GENERATED_BODY()
	
public:
	AHitEffect();

	virtual void Tick(float dt) override;
	
protected:
	virtual void OnEnable() override;

	UPROPERTY()
	float Timer;
};
