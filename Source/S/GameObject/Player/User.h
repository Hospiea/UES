// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/GameObjects.h"
#include "User.generated.h"

/**
 * 
 */
UCLASS()
class S_API AUser : public AGameObjects
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;
};
