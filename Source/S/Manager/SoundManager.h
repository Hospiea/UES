// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundManager.generated.h"

class USoundAsset;
class UAudioComponent;

UCLASS()
class S_API ASoundManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ASoundManager();
	void PlayBgm(const FString& str, const float& Volume = (1.0f), const float& FadeIn = (0.0f), const bool& bLoop = true);
	void PlaySfx(const FString& str);


private:
	UPROPERTY()
	TObjectPtr<USoundAsset> Sounds;

	UPROPERTY()
	TObjectPtr<UAudioComponent> BgmPlayer;

	UPROPERTY()
	TArray<TObjectPtr<UAudioComponent>> SfxPlayer;


};
