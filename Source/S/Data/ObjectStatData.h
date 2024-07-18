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

	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere)
	float MaxHp;


};
