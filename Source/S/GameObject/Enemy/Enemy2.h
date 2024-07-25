// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Enemy.h"
#include "Enemy2.generated.h"

class AERange;

UCLASS()
class S_API AEnemy2 : public AEnemy
{
	GENERATED_BODY()
	
public:
	AEnemy2();

protected:
	virtual void Tick(float dt) override;

	UFUNCTION()
	void RecoverFromKnockBack();

	UPROPERTY()
	TSubclassOf<AERange> RangeClass;

	float Timer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setting")
	float Distance;
};
