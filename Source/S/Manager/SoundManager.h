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
	void PlayBgm(const FString& str);
	void PlaySfx(const FString& str);


private:
	UPROPERTY()
	TObjectPtr<USoundAsset> Sounds;

	UPROPERTY()
	TObjectPtr<UAudioComponent> BgmPlayer;

	UPROPERTY()
	TObjectPtr<UAudioComponent> SfxPlayer;

};
