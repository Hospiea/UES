// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/Melee.h"
#include "PChakramBody.generated.h"

class APChakram;

UCLASS()
class S_API APChakramBody : public AMelee
{
	GENERATED_BODY()
	
public:
	APChakramBody();

	inline void SetCenter(APChakram* center) { Center = center; }
	inline void SetRight(const bool& flag) { bIsRight = flag; }

protected:
	virtual void Tick(float dt) override;

protected:
	UPROPERTY()
	TObjectPtr<APChakram> Center;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotate Property")
	float RotateSpeed = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotate Property")
	float RotateRadius = 50.0f;

	bool bIsRight;
	float Timer;
};
