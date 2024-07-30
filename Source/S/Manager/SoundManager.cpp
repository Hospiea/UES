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

	SfxPlayer = CreateDefaultSubobject<UAudioComponent>(TEXT("SfxPlayer"));
	SfxPlayer->bAutoActivate = false;
	SfxPlayer->SetupAttachment(RootComponent);
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
	SfxPlayer->SetSound(Sounds->Sfx[str]);
	SfxPlayer->Play();
}


