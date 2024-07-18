// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Attacks/Basic/Basic.h"
#include "Sword.generated.h"

class APSword;

UCLASS()
class S_API USword : public UBasic
{
	GENERATED_BODY()
	
public:
	USword();
	virtual void BasicAttack() override;

	UPROPERTY()
	TSubclassOf<APSword> SwordClass;
};
