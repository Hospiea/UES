// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles/Melee.h"
#include "PSword.generated.h"



UCLASS()
class S_API APSword : public AMelee
{
	GENERATED_BODY()

public:
	APSword();

protected:
	virtual void BeginPlay() override;


	
};
