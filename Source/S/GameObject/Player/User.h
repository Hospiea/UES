// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/GameObjects.h"
#include "User.generated.h"

class UCenter;
class UBasic;

UCLASS()
class S_API AUser : public AGameObjects
{
	GENERATED_BODY()

public:
	AUser();
	TObjectPtr<UCenter>& GetCenter() { return Center; }
	TObjectPtr<UBasic>& GetBasicAttack() { return Basic; }

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCenter> Center;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBasic> Basic;
};