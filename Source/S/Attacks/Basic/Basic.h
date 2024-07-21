// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Basic.generated.h"

class AUser;
class UWorld;
class UWeaponAsset;
class AProjectiles;
struct WeaponData;

UCLASS()
class S_API UBasic : public UObject
{
	GENERATED_BODY()
	
public:
	UBasic(const FObjectInitializer& Init);
	virtual ~UBasic() override;
	virtual void BasicAttack(const FVector2D& Dir);
	inline void SetPlayer(AUser* user) { User = user; }
	inline void SetWorld(UWorld* world) { World = world; }
	virtual void Init();
	const float& GetRate() { return Rate; }
	inline WeaponData& GetData() { return *Data; }

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
	FVector SpawnLocation;

	WeaponData* Data;
	
	UPROPERTY()
	TObjectPtr<UWeaponAsset> Weapons;

	UPROPERTY()
	TSubclassOf<AProjectiles> WeaponClass;
};
