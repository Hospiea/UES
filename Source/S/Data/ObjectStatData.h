// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ObjectStatData.generated.h"

/**
 * 
 */
UCLASS()
class S_API UObjectStatData : public UDataTable
{
	GENERATED_BODY()
	

};



USTRUCT()
struct S_API FEnemyStats : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere)
	float MaxHp;


};


USTRUCT()
struct S_API FPlayerStats : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere)
	float Speed;

	UPROPERTY(VisibleAnywhere)
	float MaxHp;

	UPROPERTY(VisibleAnywhere)
	float HPRegen;

	UPROPERTY(VisibleAnywhere)
	float Defense;

	UPROPERTY(VisibleAnywhere)
	float ExpValue;

	UPROPERTY(VisibleAnywhere)
	float SourceValue;

	UPROPERTY(VisibleAnywhere)
	float UntouchableTime;

	UPROPERTY(VisibleAnywhere)
	float ObtainRange;

	UPROPERTY(VisibleAnywhere)
	float AttackValue;

	UPROPERTY(VisibleAnywhere)
	float Rate;

	UPROPERTY(VisibleAnywhere)
	float ProjectileSpeed;

	UPROPERTY(VisibleAnywhere)
	float ProjectileSize;

	UPROPERTY(VisibleAnywhere)
	float ProjectileDuration;


};


USTRUCT()
struct S_API FExpData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float RequiredExp;
};