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
class UAttackComponent;

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
	inline TObjectPtr <UDetectComponent>& GetDetectComponent() { return DetectComponent; }

	void GetExp(const float& value);
	inline const uint8& GetLevel() { return Level; }
	inline const float GetExpPercent() {
		return CurExp / RequiredExp[Level]->RequiredExp;
	}


protected:
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;
	void LevelUp();

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

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAttackComponent> AttackComponent;

	TArray<FExpData*> RequiredExp;

	PlayerStats Stats;

	UPROPERTY()
	float CurHp;

	UPROPERTY()
	float CurExp;

	UPROPERTY()
	uint8 Level;
};