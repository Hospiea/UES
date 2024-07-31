// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/GameObjects.h"
#include "Enemy.generated.h"

class AUser;
class AAIC;
class AExpOrb;

USTRUCT()
struct FEnemyStat
{
	GENERATED_BODY()
	float Speed;
	float MaxHp;
};

UCLASS()
class S_API AEnemy : public AGameObjects
{
	GENERATED_BODY()

public:
	

	enum class EnemyState
	{
		Normal,
		KnockBacked,
		Electricted,
		Slowed,
		Poisoned,
		Recovering,
		Attacking,
		Dead,
		Hold,
	};
	AEnemy();

	inline const EnemyState& GetEnemyState() { return State; }
	void SetEnemyState(const EnemyState& state);
	virtual void GetDamage(const float& value) override;
	inline const bool& GetArmorDamaged() { return IsArmored; }
	void SetArmorDamaged();

protected:
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float dt) override;
	virtual void OnEnable() override;
	void SetActiveHelper();
	
	FTimerHandle TimerHandle;

	EnemyState State;

	UPROPERTY()
	TObjectPtr<AUser> Target;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AAIC> AIController;

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	

	UPROPERTY()
	float CurHp;

	UPROPERTY()
	bool IsArmored;

	UPROPERTY()
	uint8 ExpLv;

	UPROPERTY()
	TSubclassOf<AExpOrb> OrbClass;

	UFUNCTION()
	void RecoverColor();

	UFUNCTION()
	void RecoverFromKnockBack();

	static bool bIsInitted;
};
