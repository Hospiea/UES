// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/GameObjects.h"
#include "User.generated.h"

class UCenter;
class UBasic;
class USWidgetComponent;


UCLASS()
class S_API AUser : public AGameObjects
{
	GENERATED_BODY()

public:
	struct PlayerStats
	{
		float Speed;
		float MaxHp;
	};



	AUser();
	inline const PlayerStats& GetStats() { return Stats; }
	TObjectPtr<UCenter>& GetCenter() { return Center; }
	TObjectPtr<UBasic>& GetBasicAttack() { return Basic; }

protected:
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCenter> Center;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBasic> Basic;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<USWidgetComponent> HPBar;

	PlayerStats Stats;

	UPROPERTY()
	float CurHp;
};