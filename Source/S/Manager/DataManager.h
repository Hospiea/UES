// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Data/ObjectStatData.h"
#include "DataManager.generated.h"


UCLASS()
class S_API UDataManager : public UObject
{
	GENERATED_BODY()
	
public:
	UDataManager(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UDataTable> PlayerStats;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UDataTable> EnemyStats;
};
