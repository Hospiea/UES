// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Asset.h"
#include "SoundAsset.generated.h"

class USoundWave;

UCLASS()
class S_API USoundAsset : public UAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TMap<FString, TObjectPtr<USoundWave>> Bgm;

	UPROPERTY(EditAnywhere)
	TMap<FString, TObjectPtr<USoundWave>> Sfx;
};
