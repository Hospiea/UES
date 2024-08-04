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
class AObtainer;

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
	inline PlayerStats& GetStats() { return Stats; }
	inline TObjectPtr<UCenter>& GetCenter() { return Center; }
	inline TObjectPtr <UDetectComponent>& GetDetectComponent() { return DetectComponent; }
	inline TObjectPtr<UAttackComponent>& GetAttackComponent() { return AttackComponent; }
	inline TObjectPtr<AObtainer>& GetObtainer() { return Obtainer; }

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
	void GetDamaged(const float& value);
	void GetDamagedHelper();

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCenter> Center;


	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UDetectComponent> DetectComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<USWidgetComponent> HPBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UDataTable> ExpData;

	UPROPERTY()
	TObjectPtr<AObtainer> Obtainer;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAnimationComponent> AnimationComponent;

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