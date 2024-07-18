// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Asset.h"
#include "FlipbookAsset.generated.h"

class UPaperFlipbook;

UCLASS()
class S_API UFlipbookAsset : public UAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TMap<FString, TObjectPtr<UPaperFlipbook>> Flipbooks;
};
