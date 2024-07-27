// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Asset.h"
#include "TextureAsset.generated.h"

class UTexture2D;

UCLASS()
class S_API UTextureAsset : public UAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, TObjectPtr<UTexture2D>> Textures;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<UTexture2D>> MainWeapons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<UTexture2D>> Passives;
};
