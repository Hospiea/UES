// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Functions.generated.h"

/**
 * 
 */
UCLASS()
class S_API UFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static void PlayBgm(const FString& str, float Volume = 1.0f, float FadeIn = 0.0f, bool bLoop = true);
};
