// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/GameObjects.h"
#include "Enemy.generated.h"

class AUser;
class AAIC;
struct EnemyStats;
class AExpOrb;

UCLASS()
class S_API AEnemy : public AGameObjects
{
	GENERATED_BODY()

public:
	struct EnemyStats
	{
		float Speed;
		float MaxHp;
	};

	enum class EnemyState
	{
		Normal,
		KnockBacked,
		Electricted,
		Slowed,
		Poisoned,
		Recovering
	};
	AEnemy();

	inline const EnemyState& GetEnemyState() { return State; }
	inline void SetEnemyState(const EnemyState& state) { State = state; }
	virtual void GetDamage(const float& value) override;
	inline const bool& GetArmorDamaged() { return IsArmored; }
	void SetArmorDamaged();

protected:
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	
	FTimerHandle TimerHandle;

	EnemyState State;

	UPROPERTY()
	TObjectPtr<AUser> Target;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AAIC> AIController;

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	EnemyStats Stats;

	UPROPERTY()
	float CurHp;

	UPROPERTY()
	bool IsArmored;

	UPROPERTY()
	TSubclassOf<AExpOrb> OrbClass;
};
