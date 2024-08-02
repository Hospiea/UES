// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject/Projectiles.h"
#include "UObject/NoExportTypes.h"
#include "Basic.generated.h"

class AUser;
class UWorld;
class UWeaponAsset;
struct WeaponData;

UCLASS()
class S_API UBasic : public UObject
{
	GENERATED_BODY()
public:
	enum class AttackType : int32
	{
		Sword,
		Axe,
		Hammer,
		Spear,
		Staff,
		Dagger,
		Shield,
		Armor,
		Helmet,
		Chakram,
		Shoes,
		Negative,
		Positive
	};

	enum class PassiveType : int32
	{
		Fire,
		Wind,
		Will,
		Magnetic,
		Life,
		Iron,
		Time,
		Circular,
		Thunder,
		Rock,
		Belief,
		Experience,
		Rich
	};
	
public:
	UBasic(const FObjectInitializer& Init);
	virtual ~UBasic() override;
	virtual void BasicAttack(const FVector2D& Dir);
	inline void SetPlayer(AUser* user) { User = user; }
	inline void SetWorld(UWorld* world) { World = world; }
	virtual void Init();
	const float& GetRate() { return Rate; }
	virtual inline FProjectileData& GetData() { return Data; }
	inline const AttackType& GetAttackType() { return Type; }
	inline void SetAttackType(const AttackType& type) { Type = type; }
	inline const PassiveType& GetPassiveType() { return PType; }
	inline void SetPassiveType(const PassiveType& type) { PType = type; }
	virtual int32& GetLevel() { return Level; };
	virtual void LevelUp() 
	{ 
		Init();
	}
	inline void SetPassive(const bool& flag) { bIsPassive = flag; }
	inline const bool& IsPassive() { return bIsPassive; }

protected:
	virtual void SetWeaponData() {};

	UPROPERTY()
	TObjectPtr<AUser> User;

	UPROPERTY()
	TObjectPtr<UWorld> World;

	UPROPERTY()
	float Angle;

	UPROPERTY()
	float Rate;

	UPROPERTY()
	bool bIsPassive;

	UPROPERTY()
	FVector SpawnLocation;

	FProjectileData Data;
	
	UPROPERTY()
	TObjectPtr<UWeaponAsset> Weapons;

	UPROPERTY()
	TSubclassOf<AProjectiles> WeaponClass;

	AttackType Type;
	PassiveType PType;

	UPROPERTY()
	int32 Level;
};
