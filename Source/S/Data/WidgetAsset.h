// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Asset.h"
#include "WidgetAsset.generated.h"

class UUserWidget;

UCLASS()
class S_API UWidgetAsset : public UAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TMap<FString, TSubclassOf<UUserWidget>> Widgets;
};
