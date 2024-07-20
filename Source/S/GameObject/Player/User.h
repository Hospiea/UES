// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/GameObjects.h"
#include "Data/ObjectStatData.h"
#include "User.generated.h"

class UCenter;
class UBasic;
class USWidgetComponent;
class UDetectComponent;

UCLASS()
class S_API AUser : public AGameObjects
{
	GENERATED_BODY()

public:
	struct PlayerStats
	{
		float Speed;
		float MaxHp;
		float HPRegen;
		float Defense;
		float ExpValue;
		float SourceValue;
		float UntouchableTime;
		float ObtainRange;
		float AttackValue;
		float Rate;
		float ProjectileSpeed;
		float ProjectileSize;
		float ProjectileDuration;
	};



	AUser();
	inline const PlayerStats& GetStats() { return Stats; }
	TObjectPtr<UCenter>& GetCenter() { return Center; }
	TObjectPtr<UBasic>& GetBasicAttack() { return Basic; }
	void GetExp(const float& value);

protected:
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCenter> Center;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBasic> Basic;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UDetectComponent> DetectComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<USWidgetComponent> HPBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UDataTable> ExpData;

	TArray<FExpData*> RequiredExp;

	PlayerStats Stats;

	UPROPERTY()
	float CurHp;

	UPROPERTY()
	float CurExp;

	UPROPERTY()
	uint8 Level;
};