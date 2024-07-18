// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WeaponDataTable.generated.h"

/**
 * 
 */
UCLASS()
class S_API UWeaponDataTable : public UDataTable
{
	GENERATED_BODY()
	
};

USTRUCT()
struct S_API FWeaponData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	float Damage;

	UPROPERTY(VisibleAnywhere)
	float Rate;

	UPROPERTY(VisibleAnywhere)
	float Range;

	
};