// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Asset.h"
#include "EnemyAsset.generated.h"

class AEnemy;

UCLASS()
class S_API UEnemyAsset : public UAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TMap<FString, TSubclassOf<AEnemy>> Enemies;
};
