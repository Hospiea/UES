// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Interface/BasicAttack.h"
#include "Basic.generated.h"

class AUser;
class UWorld;
class UWeaponAsset;
class AProjectiles;

UCLASS()
class S_API UBasic : public UObject, public IBasicAttack
{
	GENERATED_BODY()
	
public:
	UBasic(const FObjectInitializer& Init);
	void BasicAttack(const FVector2D& Dir) override;
	inline void SetPlayer(AUser* user) { User = user; }
	inline void SetWorld(UWorld* world) { World = world; }
	virtual void Init() {};
	const float& GetRate() { return Rate; }

protected:
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
	
	UPROPERTY()
	TObjectPtr<UWeaponAsset> Weapons;

	UPROPERTY()
	TSubclassOf<AProjectiles> WeaponClass;
};
