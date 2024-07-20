// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Asset.h"
#include "GameObject/Projectiles.h"
#include "WeaponAsset.generated.h"


UCLASS()
class S_API UWeaponAsset : public UAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TMap<FString, TSubclassOf<AProjectiles>> Weapons;
};
