// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/SoundManager.h"
#include "Data/SoundAsset.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

// Sets default values
ASoundManager::ASoundManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	static ConstructorHelpers::FObjectFinder<USoundAsset> sounds(TEXT("/Script/S.SoundAsset'/Game/Assets/Data/Sounds.Sounds'"));
	Sounds = sounds.Object;

	BgmPlayer = CreateDefaultSubobject<UAudioComponent>(TEXT("BgmPlayer"));
	BgmPlayer->bAutoActivate = false;
	BgmPlayer->SetupAttachment(RootComponent);
	BgmPlayer->bIsUISound = true;

	//
	//BgmPlayer->SetVolumeMultiplier(0.0f);

	for (int i = 0; i < 32; ++i)
	{
		FString ComponentName = FString::Printf(TEXT("AudioComponent_%d"), i);
		auto temp = CreateDefaultSubobject<UAudioComponent>(*ComponentName);
		SfxPlayer.Add(temp);
		temp->SetupAttachment(RootComponent);
		temp->bAutoActivate = false;
		temp->VolumeMultiplier = 32.0f;
		temp->bIsUISound = true;
		
		//
		//temp->SetVolumeMultiplier(0.0f);
	}

	
}

void ASoundManager::PlayBgm(const FString& str, const float& Volume, const float& FadeIn, const bool& bLoop)
{
	//UGameplayStatics::PlaySound2D(GetWorld(), Sounds->Bgm[str]);

	BgmPlayer->Stop();
	Sounds->Bgm[str]->bLooping = bLoop;
	Sounds->Bgm[str]->Volume = Volume;
	BgmPlayer->FadeIn(FadeIn);
	BgmPlayer->SetSound(Sounds->Bgm[str]);
	BgmPlayer->Play();
	
}

void ASoundManager::PlaySfx(const FString& str)
{
	float total = SfxPlayer.Num();
	float volume = 32.0f / total;
	//float volume = 0.0f;
	bool bIsSet = false;

	for (auto it = SfxPlayer.begin(); it != SfxPlayer.end(); ++it)
	{
		if ((*it)->IsPlaying())
		{
			(*it)->SetVolumeMultiplier(volume);
			continue;
		}
		if (!bIsSet)
		{
			(*it)->SetSound(Sounds->Sfx[str]);
			(*it)->SetVolumeMultiplier(volume);
			(*it)->Play();
			bIsSet = true;
		}
	}

	if (bIsSet == false)
	{
		auto temp = NewObject<UAudioComponent>(this);
		SfxPlayer.Add(temp);
		temp->SetSound(Sounds->Sfx[str]);
		temp->SetVolumeMultiplier(volume);
		temp->Play();
	}
}