// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObject/HitEffect.h"
#include "Components/CapsuleComponent.h"
#include "PaperFlipbookComponent.h"

AHitEffect::AHitEffect()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Nothing"));
	Timer = 0.0f;
}

void AHitEffect::Tick(float dt)
{
	Super::Tick(dt);
	Timer += dt;
	if (Timer > 0.35f)
	{
		SetActive(false);
	}
}

void AHitEffect::OnEnable()
{
	Super::OnEnable();
	Timer = 0.0f;
	GetSprite()->SetPlaybackPositionInFrames(0, false);
}
